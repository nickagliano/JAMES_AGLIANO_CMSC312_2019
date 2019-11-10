#ifndef PROCESS_H
#define PROCESS_H

#include "../MemoryManagement/PageTable.h"


// Process object
class Process {

	private:
		// Process attributes (virtual PCB)
		int pid;
		int pc; // program counter
		int numPages; // how many pages the process takes up
		int arrivalTime; // when the process was brought into memory
		int status; // 0, 1, 2, 3, 4 == new, ready, waiting, running, terminated
		int priority; // 0 is highest
		PageTable* pageTable; // maps logical memory to physical memory

	public:
		Process();
		Process(int pid, int status, int priority);

		// getters
		int getPid() { return pid; }
		int getStatus() { return status; }
		int getPriority()  { return priority; }
		int getArrivalTime()  { return arrivalTime; }
		int getNumPages()  { return numPages; }
		PageTable* getPageTabe() { return pageTable; }

		// setters
		void setProcess(int pid, int status, int priority);
		int setArrivalTime();
		void setStatus(int s);
		void setNumPages(int n);
		void setPriority(int priority);
		void setPageTable(int numPages);

		// print
		void printProcess();

};

#endif
