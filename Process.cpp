#include "Process.h"
#include <iostream>
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

void Process::printProcess() {
	cout << "--------------------------------------------------------" << endl;
	cout << "Pid:" << endl;
	cout << this->pid << endl;
	cout << "Status:" << endl;
	cout << this->status << endl;
	cout << "Priority:" << endl;
	cout << this->priority << endl;
	cout << "--------------------------------------------------------" << endl;
}
