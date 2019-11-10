#include "MainMemory.h"
#include "Frame.h"
#include "../ProcessManagement/Process.h"
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
	this->numFreeVirtualFrames = 512;
}


// Member functions

// Setters
void MainMemory::setNumFreeFrames(int n) {
	this->numFreeFrames = n;
}

void MainMemory::setFrame(int n, Frame f) {
	this->frameArray[n] = f;
}

void MainMemory::setNumFreeVirtualFrames(int n) {
	this->numFreeVirtualFrames = n;
}


// Getters
Frame MainMemory::getFrame(int n) {
	return this->frameArray[n];
}

// Utility functions
