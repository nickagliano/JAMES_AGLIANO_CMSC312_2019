#ifndef PROCESS_H
#define PROCESS_H

#include "../MemoryManagement/MainMemory.h"
#include "../MemoryManagement/PageTable.h"
#include "Instruction.h"


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
		PageTable* pageTable; 
		list<Instruction> instructions;


	public:
		Process();
		Process(int pid, int numPages, int status, int priority, list<Instruction> instructions);

		// getters
		int getPid() { return pid; }
		int getPC() { return pc; }
		int getStatus() { return status; }
		int getPriority()  { return priority; }
		int getArrivalTime()  { return arrivalTime; }
		int getNumPages()  { return numPages; }
		list<Instruction> getInstructions()  { return instructions; }
		PageTable* getPageTable()  { return pageTable; }

		// setters
		void setProcess(int pid, int numPages, int status, int priority, list<Instruction> instructions);
		int setArrivalTime();
		void setStatus(int s);
		void setPC(int pc);
		void setNumPages(int n);
		void setPriority(int priority);
		void setInstructions(list<Instruction> instructions);
		void setInstruction(int pc, int newBT);

		// print
		void printProcess();

};

#endif
