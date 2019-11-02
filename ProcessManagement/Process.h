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
		int isIO; // boolean to check if it's an IO process or not

	public:
		Process();
		Process(int pid, int status, int priority, int burstTime, int isIO);

		// getters
		int getPid() { return pid; }
		int getStatus() { return status; }
		int getPriority()  { return priority; }
		int getArrivalTime()  { return arrivalTime; }
		int getBurstTime()  { return burstTime; }
		int getIsIO()  { return isIO; }

		// setters
		void setProcess(int pid, int status, int priority, int burstTime);
		void setBurstTime(int bt);
		int setArrivalTime();
		void setStatus(int s);
		void setPriority(int priority);
		void setIsIO(int bool);

		// print
		void printProcess();

};

#endif
