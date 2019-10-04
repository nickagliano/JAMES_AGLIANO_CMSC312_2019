#include <iostream>
using namespace std;
#include <string>
#include "Process.h"
#include "Scheduler.h"
#include "ProgramFileRandomizer.h"

// Declare global variables
// here
// more here
// even more here

// ***************************** MAIN *****************************************
int main(int argc, char**argv) {

	// // program file generation code
	// ProgramFileRandomizer* ProgramFileRandomizer = new class ProgramFileRandomizer();
	//
	// ProgramFileRandomizer->randomize();

	// Process* testProcess = new Process(1, 2, 3);
	// testProcess->setProcess(1, 2, 3);
	// testProcess->printProcess();

	Scheduler* Scheduler = new class Scheduler();

	Scheduler->readProgramFile("programFiles/randomFile1.txt");


}
