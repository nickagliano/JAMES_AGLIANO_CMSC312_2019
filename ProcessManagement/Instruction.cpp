#include "Instruction.h"
#include <iostream>
#include <string>
using namespace std;


Instruction::Instruction() {
	this->type = -1;
	this->burstTime = -1;
	this->isCritical = -1;
}

// Constructor
Instruction::Instruction(int type, int burstTime, bool isCritical) {
	this->type = type; // 0, 1, 2, or 3 || CALCULATE, I/O, YIELD, or OUT
	this->burstTime = burstTime;
	this->burstTimeLeft = burstTime;
	this->isCritical = isCritical;
}

// Member functions

// setters
void Instruction::setBurstTimeLeft(int x) {
	this->burstTimeLeft = x;
}

// print
void Instruction::printInstruction() {

	if (this->type == 0) {
		string type = "CALCULATE";
	} else if (this->type == 1) {
		string type = "I/O";
	} else if (this->type == 2) {
		string type = "YIELD";
	} else if (this->type == 3) {
		string type = "OUT";
	}

	cout << "Type of instruction: " << type << endl;
	cout << "Burst time: " << this->burstTime << endl;
	cout << "Burst time left: " << this->burstTimeLeft << endl;
	cout << "Has critical section?: " << this->isCritical << endl;
	cout << "--------------------------------------------------------" << endl;
}
