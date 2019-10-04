#include "Process.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Process::Process() {
	setProcess(0, 0, 0);
}

// Constructor
Process::Process(int pid, int status, int priority) {
	setProcess(pid, status, priority);
}

// Member functions
void Process::setProcess(int pid, int status, int priority) {
	this->pid = pid;
	this->status = status;
	this->priority = priority;
}

void Process::setPriority(int priority) {
	this->priority = priority;
}

void Process::printProcess() {
	cout << "--------------------------------------------------------" << endl;
	cout << "Pid: " << this->pid << endl;
	cout << "Status: " << this->status << endl;
	cout << "Priority:" << this->priority << endl;
	cout << "--------------------------------------------------------" << endl;
}
