#include <iostream>
using namespace std;
#include "Process.h"
#include "ProgramFileRandomizer.h"

// Declare global variables
// here
// more here
// even more here

// ***************************** MAIN *****************************************
int main(int argc, char**argv) {

	// Sceduler* scheduler = new Scheduler();

	// Process* testProcess = new Process(1, 2, 3);
	// testProcess->setProcess(1, 2, 3);
	// testProcess->printProcess();

	ProgramFileRandomizer* ProgramFileRandomizer = new class ProgramFileRandomizer();

	ProgramFileRandomizer->randomize();


}
