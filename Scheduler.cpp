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
					ioProcess.setProcess(generatePid(), 1, 0, ioValue);
					incrementNumProcesses();

					addToQueue(1, ioProcess);

				} else if (line.substr(0, 3).compare("CAL") == 0) { // a calculate process
					calcValue = stoi(line.substr(10, line.length()-1));

					Process calcProcess;
					calcProcess.setProcess(generatePid(), 1, 0, calcValue);
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


// pass queue object you want to print
void Scheduler::printQueue(queue<Process> q) {
	//printing content of queue
	while (!q.empty()) {
		q.front().printProcess();
		q.pop();
	}
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

	// while there's still processes that need to be run,
	firstComeFirstServe(); // schedule processes,
	// dispatch();
	// execute x units of process time? (1 clock cycle?)
	// repeat

}


// set which algorithm will be used by the scheduler
void Scheduler::setAlgorithm(int algorithm) {
	if (algorithm == 0) {
		this->algorithm = 0;
	} else if (algorithm == 1) {
		this->algorithm = 1;
	}
}

// generates a unique PID
int Scheduler::generatePid() {
	int pid = getPidCounter();
	this->pidCounter++;
	return pid;
}

void Scheduler::setReadyQueue(queue<Process> rq) {
	this->readyQueue = rq;
}

void Scheduler::incrementNumProcesses() {
	this->numProcesses++;
}

void Scheduler::dispatch() {
	// choose which process to put on the cpu using priority, and scheduling algorithm specific logic
	// for now, just find highest priority
	// cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
}

// ----------------------- SCHEDULING ALGORITHMS ------------------------------

// first come first serve scheduling algorithm
// 	input a process,
// 		return int priority value for that process according to when it arrived
			// in the queue relative to other processes
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

// round robin scheduling algorithm
void Scheduler::roundRobin() {

// int tq = 20 // time quantum

}
