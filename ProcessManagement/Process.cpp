#include "Process.h"
#include "../MemoryManagement/Frame.h"
#include "../MemoryManagement/MainMemory.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Process::Process() {
	setProcess(-1, 0, 0, 0, NULL);
	// Scheduler::incrementNumProcesses(); // add the
}

// Constructor
Process::Process(int pid, int numPages, int status, int priority, Instruction instructions[]) {
	setProcess(pid, numPages, status, priority, instructions);
	// Scheduler::incrementNumProcesses();
	// this->arrivalTime = setArrivalTime(); // set arrivalTime using current time returned by clock class
}

// Member functions

// setters
void Process::setProcess(int pid, int numPages, int status, int priority, Instruction instructions[]) {
	this->pid = pid; // unique process identifier
	this->numPages = numPages;
	this->status = status;
	this->priority = priority;
	this->pc = 0; // initialize pc to 0, 1st instruction
	// this->arrivalTime = // get arrivalTime from clock class
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

void Process::setPageTable(int numPages, MainMemory* ram) {
	int tempTable[numPages][2];

	for (int i = 0; i < numPages; i++) {
		tempTable[i][0] = -1;
		tempTable[i][1] = 0;
	}

	this->pageTable->setTable(tempTable);
}


// print
void Process::printProcess() {
	// cout << "--------------------------------------------------------" << endl;
	cout << "Pid: " << this->pid << endl;
	cout << "Status: " << this->status << endl;
	cout << "Priority:" << this->priority << endl;
	cout << "Number of pages allocated:" << this->numPages << endl;
	cout << "--------------------------------------------------------" << endl;
}

void Process::printPageTable() {
	int** tempTable = getPageTable()->getTable();

	for (int i = 0; i < tempTable.size(); i++){
		cout << "Page num: " << i << ", maps to frame: " << tempTable[i][0] << ", isValid?: " << tempTable[i][1] << endl;
	}

}
