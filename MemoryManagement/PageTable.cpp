#include "PageTable.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
PageTable::PageTable(int pid, int numPages) {
	this->pid = pid;
	this->numPages = numPages;
	
	for (int i = 0; i < numPages; i++) {
		this->table[i] = -1;
	}
}


// Member functions

// Setters
void PageTable::setPid(int n) {
	this->pid = n;
}


// Getters
void PageTable::print() {
	cout << "Pid: " << pid << endl;
	cout << "Number of pages: " << numPages << endl;
	for (int i = 0; i < numPages; i++) {
		cout << "Page " << i << ": " << table[i] << endl;
	}
}


// Utility functions
