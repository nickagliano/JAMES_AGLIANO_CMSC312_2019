#include <fstream> // for file writing
#include <iostream>
#include <string>
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

				} else if (line.substr(0, 3).compare("CAL") == 0) { // a calculate process
					calcValue = stoi(line.substr(10, line.length()-1));

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

	cout << "The program name: " << programName << "\n" << endl;
	cout << "The total runtime: " << totalRuntime << "\n" << endl;
	cout << "The memory: " << memory << "\n" << endl;
	cout << "The last calc process value: " << calcValue << "\n" << endl;
	cout << "The last I/O process value: " << ioValue << "\n" << endl;
}



// pass a queue (readyQueue, waitingQueue, etc.), and which process to ADD to that queue
void Scheduler::addToQueue(queue<Process> queue, int pid) {

}

// pass a queue (readyQueue, waitingQueue, etc.), and which process to REMOVE from that queue
void Scheduler::removeFromQueue(queue<Process> queue, int pid) {

}


// first come first serve scheduling algorithm
// void Scheduler::firstComeFirstServe() {
//
// 	// declare structures
// 	queue<Process> readyQueue;
// 	queue<Process> waitingQueue;
// 	queue<Process> exitQueue;
// 	list<Process> blockedQueue;
// 	Process runningProcess;
//
// 	// do the algorithm
// }
//
// // round robin scheduling algorithm
// void Scheduler::roundRobin() {
//
// }
