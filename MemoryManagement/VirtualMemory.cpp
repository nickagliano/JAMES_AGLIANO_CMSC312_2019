#include "VirtualMemory.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
VirtualMemory::VirtualMemory() {
	setVirtualMemory(-1, 0, 0, 0);

}

// Constructor
VirtualMemory::VirtualMemory(int pid, int status, int priority, int burstTime) {
	setVirtualMemory(pid, status, priority, burstTime);
	// Scheduler::incrementNumVirtualMemoryes();
	// this->arrivalTime = setArrivalTime(); // set arrivalTime using current time returned by clock class
}

// Member functions

// setters
void VirtualMemory::setVirtualMemory(int pid, int status, int priority, int burstTime) {
	this->pid = pid;
	this->status = status;
	this->priority = priority;
	this->burstTime = burstTime;
}

void VirtualMemory::setPriority(int priority) {
	this->priority = priority;
}

void VirtualMemory::setBurstTime(int bt) {
	this->burstTime = bt;
}

void VirtualMemory::setStatus(int s) {
	this->status = s;
}


// print
void VirtualMemory::printVirtualMemory() {
	// cout << "--------------------------------------------------------" << endl;
	cout << "Pid: " << this->pid << endl;
	cout << "Status: " << this->status << endl;
	cout << "Priority:" << this->priority << endl;
	cout << "Burst time: " << this->burstTime << endl;
	cout << "--------------------------------------------------------" << endl;
}
