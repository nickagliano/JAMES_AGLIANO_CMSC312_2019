#include <iostream>
using namespace std;
#include <string>
#include <queue>
#include "ProcessManagement/Process.h"
#include "ProcessManagement/Scheduler.h"
#include "ProcessManagement/Instruction.h"
#include "MemoryManagement/MainMemory.h"
#include "MemoryManagement/Frame.h"
#include "Clock.h"
// #include "ProgramFileRandomizer.h"

// Declare global variables
int systemStatus = 0;

// ***************************** MAIN *****************************************
int main(int argc, char**argv) {

	// **************** program file generation code **************************
	// ProgramFileRandomizer* ProgramFileRandomizer = new class ProgramFileRandomizer();
	//
	// ProgramFileRandomizer->randomize();

	// ************************************************************************

	// Declaration of OS components

	// Clock* clock = new class Clock(); // clock

	// Memory management
	MainMemory* ram = new class MainMemory(); // main memory / physical memory / RAM
	// VirtualMemory* vRam = new class VirtualMemory(); // virtual memory
	// SecondaryStorage* secondaryStorage = new class SecondaryStorage(); // Seconday storage / hard drive

	// Process management
	// Scheduler* scheduler = new class Scheduler(0); // declare scheduler, use firstComeFirstServe algorithm
	Scheduler* scheduler = new class Scheduler(1); // declare scheduler, use RR algorithm
	scheduler->setMainMemory(ram); // pass main memory to scheduler

	// ************************************************************************

	scheduler->readProgramFile("programFiles/randomFile1.txt"); // process a program file
	scheduler->readProgramFile("programFiles/randomFile2.txt"); // process a program file

	scheduler->printQueue(scheduler->getReadyQueue());


	// where steps / loop cycles are run
	// while (1) {
	//
	// 	if (scheduler->getReadyQueue().size() > 0) {
	// 		scheduler->step();
	// 		clock->step(); // increment clock by 1 loop cycle
	// 		cout << clock->getTime() << endl;
	// 	} else {
	// 		cout << "Nothing in ready queue" << endl;
	// 		cout << "Finished in: " << clock->getTime() << " loop cycles."<< endl;
	//
	// 		break;
	// 	}

	// }

	// scheduler->run();

	// scheduler->printQueue(scheduler->getExitQueue());

}
