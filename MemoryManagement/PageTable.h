#ifndef PAGETABLE_H
#define PAGETABLE_H

// PageTable object
class PageTable{

	private:
		int pid;
		int arrivalTime;

		int burstTime;
		int status;
		int priority;

	public:
		PageTable();
		PageTable(int pid, int status, int priority, int burstTime);

		// getters
		int getPid() { return pid; }
		int getStatus() { return status; }
		int getPriority()  { return priority; }
		int getArrivalTime()  { return arrivalTime; }
		int getBurstTime()  { return burstTime; }

		// setters
		void setPageTable(int pid, int status, int priority, int burstTime);
		void setBurstTime(int bt);
		int setArrivalTime();
		void setStatus(int s);
		void setPriority(int priority);

		// print
		void printPageTable();

};

#endif
