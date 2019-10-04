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
}

// parameterized constructor
Scheduler::Scheduler(int algorithm) {
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
					ioProcess.setProcess(ioProcess.generatePid(), 0, 0);
					// ioProcess.printProcess();

					addToQueue(1, ioProcess);

				} else if (line.substr(0, 3).compare("CAL") == 0) { // a calculate process
					calcValue = stoi(line.substr(10, line.length()-1));

					Process calcProcess;
					calcProcess.setProcess(calcProcess.generatePid(), 0, 0);
					// calcProcess.printProcess();

					addToQueue(1, calcProcess);

				} else if (line.substr(0, 3).compare("EXE") == 0) { // end command
					cout << "Found execute command: " << line << endl;

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
//
// // pass an int corresponding to a queue (readyQueue == 1, waitingQueue == 2, etc.), and which process to REMOVE from that queue
// void Scheduler::removeFromQueue(queue<Process> queue, int pid) {
//
// }

// pass queue object you want to print
void Scheduler::printQueue(queue<Process> q) {
	//printing content of queue
	while (!q.empty()) {
		cout << "hi" << endl;
		q.front().printProcess();
		q.pop();
	}
}


// calculates a process' priority given based on what algorithm is set to
int Scheduler::calcPriority(Process p) {
	if (this->algorithm == 0) {
		return firstComeFirstServe(p);
	} else if (this->algorithm == 1) {
		return roundRobin(p);
	}
}


// set which algorithm will be used by the scheduler
void Scheduler::setAlgorithm(int algorithm) {
	if (algorithm == 0) {
		this->algorithm = 0;
	} else if (algorithm == 1) {
		this->algorithm = 1;
	}
}

// ----------------------- SCHEDULING ALGORITHMS ------------------------------

// first come first serve scheduling algorithm
// 	input a process,
// 		return int priority value for that process according to when it arrived
			// in the queue relative to other processes
int Scheduler::firstComeFirstServe(Process p) {

	int priority = 9;

	return priority;
}


// round robin scheduling algorithm
void Scheduler::roundRobin(Process p) {

}
