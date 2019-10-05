#ifndef PROCESS_H
#define PROCESS_H

// Process object
class Process {

	private:
		// Process attributes (virtual PCB)
		int pid;
		int arrivalTime;
		int burstTime;
		int status;
		int priority;

	public:
		Process();
		Process(int pid, int status, int priority, int burstTime);

		int getPid() { return pid; }
		int getStatus() { return status; }
		int getPriority()  { return priority; }
		int getArrivalTime()  { return arrivalTime; }
		int getBurstTime()  { return burstTime; }

		// setter (function defined in Process.cpp)
		void setProcess(int pid, int status, int priority, int burstTime);
		void setBurstTime(int bt);

		int setArrivalTime();

		void setPriority(int priority);

		void printProcess();

};

#endif
