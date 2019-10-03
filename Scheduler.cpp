#include "Process.h"
#include "Scheduler.h"
#include "Clock.h"

#include <iostream>
using namespace std;

// Declare global variables
// here
// more here
// even more here


void Scheduler::readProgramFile() {
	// takes "program file" text file as input

	// reads program file,
	//	interprets attributes: name, total runtime, memory,
	//	and then finally, operations (CALCULATE, I/O, etc. ... EXE)

	// generates user-specified number of processes from program file (hence randomization of values from templates must be used)

	// return a process object
}

// function to calculate the priority of process
int Scheduler::calculatePriority() {

}

// first come first serve scheduling algorithm
void Scheduler::firstComeFirstServe() {

	// declare structures
	queue<Process> readyQueue;
	queue<Process> waitingQueue;
	queue<Process> exitQueue;
	list<Process> blockedQueue;
	Process runningProcess;

	// declare variables
	int time = 0;

	// do the algorithm
}

// round robin scheduling algorithm
void Scheduler::roundRobin() {

}
