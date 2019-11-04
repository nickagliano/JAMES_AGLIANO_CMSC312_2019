#ifndef PROCESS_H
#define PROCESS_H

// Process object
class Process {

	private:
		// Process attributes (virtual PCB)
		int pid;
		int arrivalTime;
		int burstTime;
		int status; // 0, 1, 2, 3, 4 == new, ready, waiting, running, terminated
		int priority;
		int type; // int to check if it's a CALC process, IO process, YIELD, or OUT

	public:
		Process();
		Process(int pid, int status, int priority, int burstTime, int type);

		// getters
		int getPid() { return pid; }
		int getStatus() { return status; }
		int getPriority()  { return priority; }
		int getArrivalTime()  { return arrivalTime; }
		int getBurstTime()  { return burstTime; }
		int getType()  { return type; }

		// setters
		void setProcess(int pid, int status, int priority, int burstTime, int type);
		void setBurstTime(int bt);
		int setArrivalTime();
		void setStatus(int s);
		void setPriority(int priority);
		void setType(int x);

		// print
		void printProcess();

};

#endif
