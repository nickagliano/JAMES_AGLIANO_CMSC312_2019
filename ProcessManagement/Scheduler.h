#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
#include <queue>
#include <list>
#include "../MemoryManagement/MainMemory.h"
using namespace std;

class Scheduler {

	private:
		queue<Process> readyQueue;
		queue<Process> waitingQueue;
		queue<Process> exitQueue;
		int algorithm;
		int pidCounter;
		int numProcesses;
		MainMemory* ram;
		Process runningProcess;

	public:
		// default constructor
		Scheduler();

		// parameterized constructor (choose which algorithm to use)
		Scheduler(int algorithm);

		// ---------------------- MEMBER FUNCTIONS ----------------------------

		// getters
		queue<Process> getReadyQueue() { return readyQueue; }
		queue<Process> getWaitingQueue() { return waitingQueue; }
		queue<Process> getExitQueue() { return exitQueue; }
		Process getRunningProcess() { return runningProcess; }
		int getPidCounter() { return pidCounter; }
		int getNumProcesses() { return numProcesses; }
		MainMemory* getMainMemory() { return ram; }


		// setters (need to figure out what i need to be able to set)
		void setReadyQueue(queue<Process> rq);
		void setWaitingQueue(queue<Process> wq);
		void setExitQueue(queue<Process> eq);
		void setRunningProcess(Process p);
		void setAlgorithm(int algorithm);
		void setMainMemory(MainMemory* ram);

		// utility funcitons
		void run();
		void step();
		void dispatch();
		void readProgramFile(string filePath);
		int generatePid();
		void incrementPidCounter();
		void incrementNumProcesses();
		void addToQueue(int queue, Process p);
		// void removeFromQueue(int queue, int pid);
		void printQueue(queue<Process> queue);
		void threadTest();

		// scheduling algorithms
		void firstComeFirstServe();
		void roundRobin();
		void roundRobinStep(int tq);


};

#endif
