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

		// setters (need to figure out what i need to be able to set)
			// here
			//	and here
			// 		etc...

		// member functions
		void readProgramFile(string filePath);

		void addToQueue(queue<Process> queue, Process process);

		void removeFromQueue(queue<Process> queue, int pid);

		void setAlgorithm(int algorithm);

		void firstComeFirstServe();

		void printQueue(queue<Process> queue);


		// void roundRobin();
		//
		int calculatePriority();
};

// how to declare dispatcher object? it should probably inherit scheduler / be a subclass
// Dispatcher object
// class Dispatcher {
//
// 		// Dispatcher attributes
// 		// int x;
// 		// int potato;
//
// 		// default constructor
// 		Dispatcher() {
//
// 		}
//
// 		// getter
// 		void getDispatcher() {
// 			// getter stuff
// 		}
//
// 		// setter
// 		void setDispatcher() {
// 			// setter stuff
// 		}
//
// };


#endif
