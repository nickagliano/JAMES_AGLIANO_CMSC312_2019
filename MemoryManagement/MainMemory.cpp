#include "MainMemory.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
MainMemory::MainMemory() {
	this->freeSpace = 0;
	this->kernelAddressSpace = 0;
	this->userAddressSpace = 0;
}


// Member functions

// setters
// void MainMemory::setMainMemory(int pid, int status, int priority, int burstTime) {
// 	this->pid = pid;
// 	this->status = status;
// 	this->priority = priority;
// 	this->burstTime = burstTime;
// }
