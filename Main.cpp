#include <iostream>
using namespace std;
#include <string>
#include <queue>
#include "Process.h"
#include "Scheduler.h"
// #include "ProgramFileRandomizer.h"

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


	// Scheduler* scheduler = new class Scheduler(0); // declare scheduler, use firstComeFirstServe algorithm

	Scheduler* scheduler = new class Scheduler(1); // declare scheduler, use firstComeFirstServe algorithm


	scheduler->run();

	scheduler->printQueue(scheduler->getExitQueue());

}
