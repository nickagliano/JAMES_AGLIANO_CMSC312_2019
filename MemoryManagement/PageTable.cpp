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

// print
void PageTable::printPageTable() {
	cout << "--------------------------------------------------------" << endl;
	cout << "Pid: " << this->pid << endl;
}
