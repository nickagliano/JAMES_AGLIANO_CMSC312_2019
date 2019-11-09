#ifndef PROCESS_H
#define PROCESS_H

// Instruction object
class Instruction {

	private:
		// Instruction attributes
		int pid; // pid which the instruction belongs to
		int burstTime;
		int burstTimeLeft;
		int status; // 0, 1, 2, 3, 4 == new, ready, waiting, running, terminated
		int priority;
		int type; // int to check if it's CALC, IO, YIELD, or OUT, 0, 1, 2, or 3

	public:
		Instruction();
		Instruction(int pid, int status, int priority, int burstTime, int type);

		// getters
		int getPid() { return pid; }
		int getStatus() { return status; }
		int getPriority()  { return priority; }
		int getArrivalTime()  { return arrivalTime; }
		int getBurstTime()  { return burstTime; }
		int getType()  { return type; }

		// setters
		void setInstruction(int pid, int status, int priority, int burstTime, int type);
		void setBurstTime(int bt);
		int setArrivalTime();
		void setStatus(int s);
		void setPriority(int priority);
		void setType(int x);

		// print
		void printInstruction();

};

#endif
