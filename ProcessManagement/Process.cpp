#include "Process.h"
#include "../MemoryManagement/Frame.h"
#include "../MemoryManagement/MainMemory.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Process::Process() {

	// Scheduler::incrementNumProcesses(); // add the
}

// Constructor
Process::Process(int pid, int numPages, int status, int priority, list<Instruction> instructions) {
	setProcess(pid, numPages, status, priority, instructions);
	// Scheduler::incrementNumProcesses();
	this->pageTable = new class PageTable(pid, numPages);
	// this->arrivalTime = setArrivalTime(); // set arrivalTime using current time returned by clock class
}

// Member functions

// setters
void Process::setProcess(int pid, int numPages, int status, int priority, list<Instruction> instructions) {
	this->pid = pid; // unique process identifier
	this->numPages = numPages;
	this->status = status;
	this->priority = priority;
	this->pc = 0; // initialize pc to 0, 1st instruction
	this->instructions = instructions;
	// this->arrivalTime = // get arrivalTime from clock class

}

void Process::setPriority(int priority) {
	this->priority = priority;
}

void Process::setPC(int pc) {
	this->pc = pc;
}



void Process::setInstructions(list<Instruction> instructions) {
	this->instructions = instructions;
}

void Process::setStatus(int s) {
	this->status = s;
}


// print
void Process::printProcess() {
	// cout << "--------------------------------------------------------" << endl;
	cout << "Pid: " << this->pid << endl;
	cout << "Status: " << this->status << endl;
	cout << "Priority: " << this->priority << endl;
	cout << "Number of pages allocated: " << this->numPages << endl;
	cout << "--------------------------------------------------------" << endl;
}
