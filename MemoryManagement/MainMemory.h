#ifndef MAINMEMORY_H
#define MAINMEMORY_H

#include <string>
#include <queue>
#include <list>
using namespace std;

class MainMemory {

	private:
		int size = 4096; // main memory size set to 4096 MB
		int frameSize = 16;
		int freeSpace;
		int kernelAddressSpace;
		int userAddressSpace;
		list<Process> processList;


	public:
		// default constructor
		MainMemory();

		// no parameterized constructor needed

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
