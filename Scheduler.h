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

		Scheduler(int algorithm);


		// getters
		queue<Process> getReadyQueue() { return readyQueue; }
		queue<Process> getWaitingQueue() { return waitingQueue; }
		queue<Process> getExitQueue() { return exitQueue; }
		list<Process> getBlockedQueue() { return blockedQueue; }
		Process getRunningProcess() { return runningProcess; }
		int getPidCounter() { return pidCounter; }
		int getNumProcesses() { return numProcesses; }


		// setters (need to figure out what i need to be able to set)
			// here
			//	and here
			// 		etc...

		// member functions
		void run();

		void readProgramFile(string filePath);

		void addToQueue(int queue, Process p);

		// void removeFromQueue(int queue, int pid);

		void setAlgorithm(int algorithm);

		void printQueue(queue<Process> queue);

		void firstComeFirstServe();

		void roundRobin();

		int generatePid();

		void incrementPidCounter();

		void incrementNumProcesses();

		void setReadyQueue(queue<Process> rq);

		void dispatch();



};

// Dispatcher object
// class Dispatcher : public Scheduler {
//
// 	private:
//
// 	public:
// };


#endif
