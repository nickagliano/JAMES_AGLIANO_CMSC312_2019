#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
#include <queue>
#include <list>
using namespace std;

class Scheduler {

	private:
		queue<Process> readyQueue;
		queue<Process> waitingQueue;
		queue<Process> exitQueue;
		list<Process> blockedQueue;
		Process runningProcess;
		int algorithm;
		int pidCounter;
		int numProcesses;

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
		list<Process> getBlockedQueue() { return blockedQueue; }
		Process getRunningProcess() { return runningProcess; }
		int getPidCounter() { return pidCounter; }
		int getNumProcesses() { return numProcesses; }


		// setters (need to figure out what i need to be able to set)
		void setExitQueue(queue<Process> eq);
		void setReadyQueue(queue<Process> rq);
		void setRunningProcess(Process p);
		void setAlgorithm(int algorithm);


		// utility funcitons
		void run();
		void dispatch();
		void readProgramFile(string filePath);
		int generatePid();
		void incrementPidCounter();
		void incrementNumProcesses();
		void addToQueue(int queue, Process p);
		// void removeFromQueue(int queue, int pid);
		void printQueue(queue<Process> queue);

		// scheduling algorithms
		void firstComeFirstServe();
		void roundRobin();


};

// Dispatcher object
// class Dispatcher : public Scheduler {
//
// 	private:
//
// 	public:
// };


#endif
