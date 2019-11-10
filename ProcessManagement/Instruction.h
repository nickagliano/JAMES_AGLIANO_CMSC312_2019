#ifndef INSTRUCTION_H
#define INSTRUCTION_H

// Instruction object
class Instruction {

	private:
		// Instruction attributes
		int type; // int to check if it's CALC, IO, YIELD, or OUT, 0, 1, 2, or 3
		int burstTime;
		int burstTimeLeft;
		bool isCritical;

	public:
		Instruction();
		Instruction(int type, int burstTime, bool isCritical);

		// getters
		int getType()  { return type; }
		int getBurstTime()  { return burstTime; }
		int getBurstTimeLeft() { return burstTimeLeft; }
		bool getIsCritical() { return isCritical; }

		// setters
		void setBurstTimeLeft(int x);

		// print
		void printInstruction();
};

#endif
