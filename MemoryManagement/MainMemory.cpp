#include "MainMemory.h"
#include "Frame.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
MainMemory::MainMemory() {
	this->kernelAddressSpace = 0;
	this->userAddressSpace = 0;

	for (int i = 0; i < 256; i++) { // instantiating memory frames
		Frame f;
		f.setAddress(i);
		this->setFrame(i, f);
	}

	for (int i = 0; i < 256; i++) { // instantiating memory frames
		Frame f;
		f.setAddress(i);
		this->freeFrameList.push_back(f);
	}

	this->numFreeFrames = 256;
}




// Member functions

// setters
// void MainMemory::setMainMemory(int pid, int status, int priority, int burstTime) {
// 	this->pid = pid;
// 	this->status = status;
// 	this->priority = priority;
// 	this->burstTime = burstTime;
// }

void MainMemory::setFrame(int n, Frame f) {
	this->frameArray[n] = f;
}

Frame MainMemory::getFrame(int n) {
	return this->frameArray[n];
}

void MainMemory::printFreeFrames() {
	list<Frame>::iterator it;
	for (it = this->freeFrameList.begin(); it != this->freeFrameList.end(); ++it){
		cout << it->getAddress();
		cout << " ";
	}
}
