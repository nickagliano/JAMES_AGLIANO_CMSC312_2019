#include <iostream>
using namespace std;
#include <string>
#include <queue>
#include "ProcessManagement/Process.h"
#include "ProcessManagement/Scheduler.h"
#include "MemoryManagement/MainMemory.h"
#include "MemoryManagement/Scheduler.h"
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



	Clock clock = new class Clock();

	// Scheduler* scheduler = new class Scheduler(0); // declare scheduler, use firstComeFirstServe algorithm
	Scheduler* scheduler = new class Scheduler(1); // declare scheduler, use RR algorithm

	MainMemory ram = new class MainMemory();


	while (1) {
		

	}

	scheduler->run();

	// scheduler->printQueue(scheduler->getExitQueue());

}
