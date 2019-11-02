#include <fstream> // for file writing
#include <iostream>
#include <string>
#include <queue>
#include <list>
using namespace std;

#include "Process.h"
#include "Scheduler.h"
// #include "Clock.h"


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


// ----------------------------------------------------------------------------

// utility functions

void Scheduler::readProgramFile(string filePath) {

	string line;
	string programName;
	string totalRuntime;
	string memory;
	int calcValue;
	int ioValue;

	ifstream myfile (filePath);

	if (myfile.is_open()) {
		while (getline(myfile, line)) { // while there's another line in the file

			if (line.length() >= 3) {

				if (line.substr(0, 3).compare("Nam") == 0) { // program name
					programName = line.substr(6, line.length()-1);

				} else if (line.substr(0, 3).compare("Tot") == 0) { // total runtime
					totalRuntime = line.substr(15, line.length()-1);

				} else if (line.substr(0, 3).compare("Mem") == 0) { // memory
					memory = line.substr(8, line.length()-1);

				} else if (line.substr(0, 3).compare("I/O") == 0) { // an i/o process
					ioValue = stoi(line.substr(4, line.length()-1));

					Process ioProcess;
					ioProcess.setProcess(generatePid(), 1, 0, ioValue, 1);
					incrementNumProcesses();

					addToQueue(1, ioProcess);

				} else if (line.substr(0, 3).compare("CAL") == 0) { // a calculate process
					calcValue = stoi(line.substr(10, line.length()-1));

					Process calcProcess;
					calcProcess.setProcess(generatePid(), 1, 0, calcValue, 0);
					incrementNumProcesses();

					addToQueue(1, calcProcess);

				} else if (line.substr(0, 3).compare("EXE") == 0) { // end command
					break;
				}
			}
		}
		myfile.close();
	} else {
		cout << "Unable to open file";
	}

	// cout << "The program name: " << programName << "\n" << endl;
	// cout << "The total runtime: " << totalRuntime << "\n" << endl;
	// cout << "The memory: " << memory << "\n" << endl;
	// cout << "The last calc process value: " << calcValue << "\n" << endl;
	// cout << "The last I/O process value: " << ioValue << "\n" << endl;
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
void Scheduler::run() {
	cout << "Starting scheduler!!" << endl;
	if (algorithm == 0) {
		cout << "Prioritizing processes using First Come First Serve algorithm" << endl;
	} else if (algorithm == 1) {
		cout << "Prioritizing processes using Round Robin algorithm" << endl;
	}

	// add funcionality to randomly generate files each run, then read through all of them
	readProgramFile("programFiles/randomFile1.txt"); // process a program file
	// readProgramFile("programFiles/randomFile2.txt"); // process a program file

	if (algorithm == 0) {
		bool runFlag = true;
		while (runFlag) { // while loop runs until every process has been executed
			firstComeFirstServe(); // schedule processes,
			dispatch(); // remove/add process to cpu depending on scheduling alogorithm

			Process rp = getRunningProcess();

			if (getReadyQueue().empty() && getWaitingQueue().empty()) { // end condition (will need to tweak later)
				runFlag = false;
			}
		}
	} else if (algorithm == 1) {
		roundRobin();
	}
}

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
	if (algorithm == 0) {
		bool runFlag = true;
		while (runFlag) { // while loop runs until every process has been executed
			firstComeFirstServe(); // schedule processes,
			dispatch(); // remove/add process to cpu depending on scheduling alogorithm

			Process rp = getRunningProcess();

			if (getReadyQueue().empty() && getWaitingQueue().empty()) { // end condition (will need to tweak later)
				runFlag = false;
			}
		}
	} else if (algorithm == 1) {
		roundRobinStep();
	}
}


// ----------------------- SCHEDULING ALGORITHMS ------------------------------

// first come first serve scheduling algorithm
void Scheduler::firstComeFirstServe() {

	queue<Process> rq = getReadyQueue();
	queue<Process> wq = getWaitingQueue();

	queue<Process> tempReadyQueue;
	int priority = 0;

	while (!rq.empty()) {
		tempReadyQueue.push(rq.front());
		rq.pop();
	}

	while(!tempReadyQueue.empty()) {
		Process p = tempReadyQueue.front();
		tempReadyQueue.pop();
		p.setPriority(priority);
		priority++;
		rq.push(p);
	}

	setReadyQueue(rq);
}


void Scheduler::roundRobinStep() {

	int tq = 20; // time quantum

	q = getReadyQueue();

	Process p = rq.front(); // get first process in queue
	p.setStatus(3); // set process status as running
	setRunningProcess(p); // set as running process
	int bt = p.getBurstTime(); // get burst time

	if (p.getBurstTime() > tq) { // if the burstTime is longer than the time quantum
		cout << "Process is running with burst time longer than time quantum, it will be put back on the queue" << endl;
		p.printProcess();
		p.setBurstTime(bt-20); // take time quantum length of time off of the burst time
		rq.pop(); // remove from queue, and...
		p.setStatus(1); // set status back to ready and...
		rq.push(p); // add to the end of queue
	} else {
		cout << "Process is running and will finish execution during this time quantum!! Congrats!!!" << endl;
		p.printProcess();
		rq.pop(); // remove from queue
		p.setBurstTime(0); // set burstTime to 0
		p.setStatus(4); // set status of process to terminated
		addToQueue(4, p); // add process to exit queue
	}

}


// round robin scheduling algorithm
void Scheduler::roundRobin() {

	int tq = 20; // time quantum

	bool done = false;
	while (!done) {

		queue<Process> rq = getReadyQueue();
		size_t size = rq.size(); // size of ready queue

		while (size-- > 0) {
			Process p = rq.front(); // get first process in queue
			p.setStatus(3); // set process status as running
			setRunningProcess(p); // set as running process
			int bt = p.getBurstTime(); // get burst time
			if (p.getBurstTime() > tq) { // if the burstTime is longer than the time quantum
				cout << "Process is running with burst time longer than time quantum, it will be put back on the queue" << endl;
				p.printProcess();
				p.setBurstTime(bt-20); // take time quantum length of time off of the burst time
				rq.pop(); // remove from queue, and...
				p.setStatus(1); // set status back to ready and...
				rq.push(p); // add to the end of queue
			} else {
				cout << "Process is running and will finish execution during this time quantum!! Congrats!!!" << endl;
				p.printProcess();
				rq.pop(); // remove from queue
				p.setBurstTime(0); // set burstTime to 0
				p.setStatus(4); // set status of process to terminated
				addToQueue(4, p); // add process to exit queue
			}
		}

		// reassess size of queue
		size = rq.size();
		if (size == 0) done = true; // if the queue is empty, stop

		setReadyQueue(rq); // push the changes from the current iteration to the 'real' readyqueue
	}
}
