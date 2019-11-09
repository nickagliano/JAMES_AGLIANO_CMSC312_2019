#include "Process.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Process::Process() {
	setProcess(-1, 0, 0, 0, 0);
	// Scheduler::incrementNumProcesses(); // add the
}

// Constructor
Process::Process(int pid, int status, int priority, int burstTime, int type) {
	setProcess(pid, status, priority, burstTime, type);
	// Scheduler::incrementNumProcesses();
	// this->arrivalTime = setArrivalTime(); // set arrivalTime using current time returned by clock class
}

// Member functions

// setters
void Process::setProcess(int pid, int status, int priority, int burstTime) {
	this->pid = pid; // unique process identifier
	this->pc = pc; // Program counter, (for this simulation represents which command process is currently on)
	this->status = status;
	this->priority = priority;
	this->burstTime = burstTime;
}

void Process::setPriority(int priority) {
	this->priority = priority;
}

void Process::setBurstTime(int bt) {
	this->burstTime = bt;
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
