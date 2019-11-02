#include "MemoryManagement/PageTable.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
PageTable::PageTable() {
	setPageTable(-1, 0, 0, 0);
	// Scheduler::incrementNumPageTablees(); // add the

}

// Constructor
PageTable::PageTable(int pid, int status, int priority, int burstTime) {
	setPageTable(pid, status, priority, burstTime);
	// Scheduler::incrementNumPageTablees();
	// this->arrivalTime = setArrivalTime(); // set arrivalTime using current time returned by clock class
}

// Member functions

// setters
void PageTable::setPageTable(int pid, int status, int priority, int burstTime) {
	this->pid = pid;
	this->status = status;
	this->priority = priority;
	this->burstTime = burstTime;
}

void PageTable::setPriority(int priority) {
	this->priority = priority;
}

void PageTable::setBurstTime(int bt) {
	this->burstTime = bt;
}

void PageTable::setStatus(int s) {
	this->status = s;
}


// print
void PageTable::printPageTable() {
	// cout << "--------------------------------------------------------" << endl;
	cout << "Pid: " << this->pid << endl;
	cout << "Status: " << this->status << endl;
	cout << "Priority:" << this->priority << endl;
	cout << "Burst time: " << this->burstTime << endl;
	cout << "--------------------------------------------------------" << endl;
}
