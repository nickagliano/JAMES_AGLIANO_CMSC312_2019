#ifndef VIRTUALMEMORY_H
#define VIRTUALMEMORY_H

#include <string>
#include <queue>
#include <list>
using namespace std;

class VirtualMemory {

	private:
		int size = 4096; // main memory size set to 4096 MB
		int pageSize;
		int freeSpace;
		list<Process> processList;


	public:
		// default constructor
		VirtualMemory();

		// parameterized constructor
		VirtualMemory();


		// ---------------------- MEMBER FUNCTIONS ----------------------------

		// getters
		int getFreeSpace() { return freeSpace; }
		int getSize() { return size; }
		list<Process> getProcessList() { return processList; }


		// setters
		void setFreeSpace(int size);


		// utility funcitons
		void printProcessList();
		list<Process> addToProcessList(Process process);
		list<Process> removeFromProcessList(Process process);
		int findFirstFit(Process process); // find first fit in memory for a process
		int findBestFit(Process process); // find best fit in memory for a process
		void shuffle(); // to reduce external fragmentation

};

#endif
