#include "Process.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Process::Process() {
	setProcess(-1, 0, 0, 0);
	// Scheduler::incrementNumProcesses(); // add the
}

// Constructor
Process::Process(int pid, int numPages, int status, int priority) {
	setProcess(pid, numPages, status, priority);
	// Scheduler::incrementNumProcesses();
	// this->arrivalTime = setArrivalTime(); // set arrivalTime using current time returned by clock class
}

// Member functions

// setters
void Process::setProcess(int pid, int numPages, int status, int priority) {
	this->pid = pid; // unique process identifier
	this->numPages = numPages;
	this->status = status;
	this->priority = priority;
	this->pc = 0; // initialize pc to 0, 1st instruction
	// this->arrivalTime = // get arrivalTime from clock class
	// this->pageTable = // initialize pageTable
}

void Process::setPriority(int priority) {
	this->priority = priority;
}

void Process::setPC(int pc) {
	this->pc = pc;
}

void Process::setStatus(int s) {
	this->status = s;
}


// print
void Process::printProcess() {
	// cout << "--------------------------------------------------------" << endl;
	cout << "Pid: " << this->pid << endl;
	cout << "Status: " << this->status << endl;
	cout << "Priority:" << this->priority << endl;
	cout << "Burst time: " << this->burstTime << endl;
	cout << "--------------------------------------------------------" << endl;
}
