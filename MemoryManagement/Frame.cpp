#include "Frame.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
Frame::Frame() {
	this->address = -1;
	this->isFree = true;
}


// Member functions

// setters
// void MainMemory::setMainMemory(int pid, int status, int priority, int burstTime) {
// 	this->pid = pid;
// 	this->status = status;
// 	this->priority = priority;
// 	this->burstTime = burstTime;
// }

void Frame::setAddress(int a) {
	this->address = a;
}

void Frame::printAddress() {
	cout << this->address;
}
