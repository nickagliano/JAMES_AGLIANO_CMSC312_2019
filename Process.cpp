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

int Process::generatePid() {
	return 10; //set to 10 just for testing until I generate a key generation
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
