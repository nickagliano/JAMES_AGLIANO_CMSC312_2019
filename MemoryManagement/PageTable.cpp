#include "MemoryManagement/PageTable.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
PageTable::PageTable() {
	setPageTable(-1);
}

// Constructor
PageTable::PageTable(int pid) {
	setPageTable(pid);
}

// Member functions

// setters
void PageTable::setPageTable(int pid) {
	this->pid = pid;
}

// getters
int PageTable::getFrameIndex(int pageIndex) {
	int isFrameValid = getValidBit(pageIndex);

	if (isFrameValid == 1) { // check to make sure frame is in memory
		return getFrameIndex(pageIndex);
	} else {
		// page fault
		// bring page in from backing store
		return null;
	}
}

// print
void PageTable::printPageTable() {
	cout << "--------------------------------------------------------" << endl;
	cout << "Pid: " << this->pid << endl;
}
