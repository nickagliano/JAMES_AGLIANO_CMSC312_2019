#include <fstream> // for file writing
#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <math.h>
using namespace std;

#include "Process.h"
#include "Scheduler.h"
#include "../MemoryManagement/MainMemory.h"


// Default constructor
Scheduler::Scheduler() {
	// this->readyQueue = value;
	// this->waitingQueue = value;
	// this->exitQueue = value;
	// this->blockedQueue = value;
	// this->runningProcess = value;
	this->pidCounter = 0;
	this->numProcesses = 0;
}

// parameterized constructor
Scheduler::Scheduler(int algorithm) {
	this->pidCounter = 0;
	setAlgorithm(algorithm);
}

// ----------------------------------------------------------------------------

// setters

void Scheduler::setReadyQueue(queue<Process> rq) {
	this->readyQueue = rq;
}

void Scheduler::setExitQueue(queue<Process> eq) {
	this->exitQueue = eq;
}

void Scheduler::setRunningProcess(Process p) {
	this->runningProcess = p;
}

// set which algorithm will be used by the scheduler
void Scheduler::setAlgorithm(int algorithm) {
	if (algorithm == 0) {
		this->algorithm = 0; // fcfs
	} else if (algorithm == 1) {
		this->algorithm = 1; // round robin
	}
}

void Scheduler::setMainMemory(MainMemory* ram) {
	this->ram = ram;
}

// ----------------------------------------------------------------------------

// utility functions

void Scheduler::readProgramFile(string filePath) {

	string line;
	string programName;
	string totalRuntime;
	int memory;
	list<Instruction> instructionList;
	int numPagesNeeded;
	bool hasRoom = false;

	int pid = generatePid();
	Process newProcess;

	ifstream myfile (filePath);

	if (myfile.is_open()) {
		while (getline(myfile, line)) { // while there's another line in the file

			if (line.length() >= 3) {

				if (line.substr(0, 3).compare("Nam") == 0) { // program name
					programName = line.substr(6, line.length()-1);

				} else if (line.substr(0, 3).compare("Tot") == 0) { // total runtime
					totalRuntime = line.substr(15, line.length()-1);

				} else if (line.substr(0, 3).compare("Mem") == 0) { // memory
					memory = stoi(line.substr(8, line.length()-1));

					numPagesNeeded = ceil(memory / 16.0f); // number of pages needed to hold process

					MainMemory* ram = getMainMemory();

					if (ram->getNumFreeVirtualFrames() < memory) {
						// cannot load into memory
						cout << "Process could not be loaded into memory because process size: " << memory << " MB is greater than free virtual memory: " << ram->getNumFreeVirtualFrames() << " GB." << endl;
						break;
					} else {
						// set boolean to true, later will be used to load process into memory
						hasRoom = true;
					}

				} else if (line.substr(0, 3).compare("YIE") == 0) { // yield
					// handle yield command

				} else if (line.substr(0, 3).compare("OUT") == 0) { // out
					// handle out command

				} else if (line.substr(0, 3).compare("I/O") == 0) { // an i/o instruction
					int ioValue = stoi(line.substr(4, line.length()-1));
					instructionList.push_back(Instruction(1, ioValue, 0));

				} else if (line.substr(0, 3).compare("CAL") == 0) { // a calculate instruction
					int calcValue = stoi(line.substr(10, line.length()-1));
					instructionList.push_back(Instruction(0, calcValue, 0));

				} else if (line.substr(0, 3).compare("EXE") == 0) { // end command
					break;
				}
			}
		}

		if (hasRoom) {


			newProcess.setProcess(pid, numPagesNeeded, 1, 0, instructionList);
			ram->setNumFreeVirtualFrames(ram->getNumFreeVirtualFrames() - numPagesNeeded);

			addToQueue(1, newProcess); // add process to ready queue
			incrementNumProcesses();


		} else {
			// add to loading buffer of some sort?
			// "new" queue?
		}

		myfile.close();
	} else {
		cout << "Unable to open file";
	}
}

// choose which process to put on the cpu using priority and logic specific to the scheduling algorithm
void Scheduler::dispatch() {
	Process runningProcess = getRunningProcess();
	queue<Process> rq = getReadyQueue();


	int highestPriority = INT_MAX;
	size_t size = rq.size();

	// find index of highest priority process
	while (size-- > 0) {
		Process p = rq.front();
		rq.pop();
		rq.push(p);
		if (p.getPriority() < highestPriority) {
			highestPriority = p.getPriority();
		}
	}

	size = rq.size();

	// process the highest priority process
	while (size-- > 0) {
		Process p = rq.front();
		if (p.getPriority() == highestPriority) {
			rq.pop();
			if (runningProcess.getPid() != -1) {
				runningProcess.setStatus(4); // change status of process to 4 (terminated)
				addToQueue(4, runningProcess);
			}
			p.setStatus(3); // set status of highest priority process to 3 (running)
			setRunningProcess(p); // add highest priority process to CPU
		} else {
			rq.pop();
			rq.push(p);
		}
	}

	setReadyQueue(rq);
}

// generates a unique PID
int Scheduler::generatePid() {
	int pid = getPidCounter();
	this->pidCounter++;
	return pid;
}

// run through processes, using scheduling parameters that were set,
//	algorithm that was specified, etc.
// void Scheduler::run() {
// 	cout << "Starting scheduler!!" << endl;
// 	if (algorithm == 0) {
// 		cout << "Prioritizing processes using First Come First Serve algorithm" << endl;
// 	} else if (algorithm == 1) {
// 		cout << "Prioritizing processes using Round Robin algorithm" << endl;
// 	}
//
// 	if (algorithm == 0) {
// 		bool runFlag = true;
// 		while (runFlag) { // while loop runs until every process has been executed
// 			firstComeFirstServe(); // schedule processes,
// 			dispatch(); // remove/add process to cpu depending on scheduling alogorithm
//
// 			Process rp = getRunningProcess();
//
// 			if (getReadyQueue().empty() && getWaitingQueue().empty()) { // end condition (will need to tweak later)
// 				runFlag = false;
// 			}
// 		}
// 	} else if (algorithm == 1) {
// 		roundRobin();
// 	}
// }

void Scheduler::incrementNumProcesses() {
	this->numProcesses++;
}

// pass queue object you want to print
void Scheduler::printQueue(queue<Process> q) {
	//printing content of queue
	while (!q.empty()) {
		q.front().printProcess();
		q.pop();
	}
}

// pass an int corresponding to a queue (readyQueue == 1, waitingQueue == 2, etc.), and which process to ADD to that queue
void Scheduler::addToQueue(int queue, Process process) {

	if (queue == 0) { // new?

	} else if (queue == 1) { // readyQueue
		this->readyQueue.push(process);

	} else if (queue == 2) { // waitingQueue
		this->waitingQueue.push(process);

	} else if (queue == 3) { // runningQueue ?


	} else if (queue == 4) { // exitQueue / terminated
		this->exitQueue.push(process);

	} else if (queue == 5) { // blockedQueue / list?

	}
}


void Scheduler::step() {

	// check if there's a new file input, or some type of interrupt
	//	if so, check if the running process can be interrupted
	//	if it can, interrupt it
	// 	if it can't (maybe it's I/O process, or in critical section), then wait

	// 	check if there's a currently running process (status 3)
	//		if no running process, pull next process according to scheduling algorithm
	//		if there is, continue processing it according to scheduling algorithm

	if (algorithm == 0) {
		bool runFlag = true;
		while (runFlag) { // while loop runs until every process has been executed
			// firstComeFirstServe(); // schedule processes,
			// dispatch(); // remove/add process to cpu depending on scheduling alogorithm
			//
			// Process rp = getRunningProcess();
			//
			// if (getReadyQueue().empty() && getWaitingQueue().empty()) { // end condition (will need to tweak later)
			// 	runFlag = false;
			// }
		}
	} else if (algorithm == 1) {
		cout << "Using round robin step" << endl;
		roundRobinStep();
	}
}


// ----------------------- SCHEDULING ALGORITHMS ------------------------------

// first come first serve scheduling algorithm
// void Scheduler::firstComeFirstServe() {
//
// 	queue<Process> rq = getReadyQueue();
// 	queue<Process> wq = getWaitingQueue();
//
// 	queue<Process> tempReadyQueue;
// 	int priority = 0;
//
// 	while (!rq.empty()) {
// 		tempReadyQueue.push(rq.front());
// 		rq.pop();
// 	}
//
// 	while(!tempReadyQueue.empty()) {
// 		Process p = tempReadyQueue.front();
// 		tempReadyQueue.pop();
// 		p.setPriority(priority);
// 		priority++;
// 		rq.push(p);
// 	}
//
// 	setReadyQueue(rq);
// }


void Scheduler::roundRobinStep() {

	int tq = 20; // time quantum

	queue<Process> rq = getReadyQueue();

	Process p = rq.front(); // get first process in queue
	p.setStatus(3); // set process status as running
	setRunningProcess(p); // set as running process
	int pc = p.getPC(); // get current PC of process

	list<Instruction> instructions = p.getInstructions();

	// if (bt > tq) { // if the burstTime is longer than the time quantum
	// 	cout << "Process is running with burst time longer than time quantum, it will be put back on the queue" << endl;
	// 	p.printProcess();
	// 	p.setInstruction(pc, bt-20); // take time quantum length of time off of the burst time
	// 	rq.pop(); // remove from queue, and...
	// 	p.setStatus(1); // set status back to ready and...
	// 	rq.push(p); // add to the end of queue
	// } else {
	// 	cout << "Process is running and will finish execution during this time quantum!! Congrats!!!" << endl;
	// 	p.printProcess();
	// 	rq.pop(); // remove from queue
	// 	p.getInstruction(pc).setBurstTimeLeft(0); // take time quantum length of time off of the burst time
	// 	p.setStatus(4); // set status of process to terminated
	// 	addToQueue(4, p); // add process to exit queue
	// }
	//
	// setReadyQueue(rq); // push the changes from the current iteration to the 'real' readyqueue

}


// round robin scheduling algorithm
// void Scheduler::roundRobin() {
//
// 	int tq = 20; // time quantum
//
// 	bool done = false;
// 	while (!done) {
//
// 		queue<Process> rq = getReadyQueue();
// 		size_t size = rq.size(); // size of ready queue
//
// 		while (size-- > 0) {
// 			Process p = rq.front(); // get first process in queue
// 			p.setStatus(3); // set process status as running
// 			setRunningProcess(p); // set as running process
// 			int bt = p.getBurstTime(); // get burst time
// 			if (p.getBurstTime() > tq) { // if the burstTime is longer than the time quantum
// 				cout << "Process is running with burst time longer than time quantum, it will be put back on the queue" << endl;
// 				p.printProcess();
// 				p.setBurstTime(bt-20); // take time quantum length of time off of the burst time
// 				rq.pop(); // remove from queue, and...
// 				p.setStatus(1); // set status back to ready and...
// 				rq.push(p); // add to the end of queue
// 			} else {
// 				cout << "Process is running and will finish execution during this time quantum!! Congrats!!!" << endl;
// 				p.printProcess();
// 				rq.pop(); // remove from queue
// 				p.setBurstTime(0); // set burstTime to 0
// 				p.setStatus(4); // set status of process to terminated
// 				addToQueue(4, p); // add process to exit queue
// 			}
// 		}
//
// 		// reassess size of queue
// 		size = rq.size();
// 		if (size == 0) done = true; // if the queue is empty, stop
//
// 		setReadyQueue(rq); // push the changes from the current iteration to the 'real' readyqueue
// 	}
// }
