#include <iostream>
#include <pthread.h>
using namespace std;
#include <string>
#include <queue>
#include "ProgramFileRandomizer.h"
#include "Clock.h"
#include "ProcessManagement/Process.h"
#include "ProcessManagement/Scheduler.h"
#include "ProcessManagement/Instruction.h"
#include "MemoryManagement/MainMemory.h"
#include "MemoryManagement/Frame.h"
#include "MemoryManagement/PageTable.h"

// Declare global variables
int systemStatus = 0;

// ***************************** MAIN *****************************************
int main(int argc, char**argv) {

	// **************** program file generation code **************************
	ProgramFileRandomizer* ProgramFileRandomizer = new class ProgramFileRandomizer();
	//
	// ProgramFileRandomizer->randomize();

	// ************************************************************************

	// Declaration of OS components
	
	Clock* clock = new class Clock(); // clock

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
	// scheduler->readProgramFile("programFiles/randomFile3.txt"); // process a program file
	// scheduler->readProgramFile("programFiles/randomFile4.txt"); // process a program file
	// 
	// for (int i = 0; i < 300; i++) {
	// 	ProgramFileRandomizer->randomize();
	// 	scheduler->readProgramFile("programFiles/random.txt"); // process a program file
	// }
	// 
	// scheduler->printQueue(scheduler->getReadyQueue());
	// cout << "number of free virtual frames: " << scheduler->getMainMemory()->getNumFreeVirtualFrames() << endl;

	// main loop -- where steps / loop cycles are run
	// while (1) {
	// 
	// 	if (scheduler->getWaitingQueue().size() > 0) {
	// 		queue<Process> wq = scheduler->getWaitingQueue();
	// 		// decrease wait times for all processes in waitQueue
	// 		// when wait time left = 0 (aka burst time left for i/o inst.), add to ready queue
	// 	}
	// 
	// 	if (scheduler->getReadyQueue().size() > 0) {
	// 		scheduler->step(); 
	// 		clock->step(); // increment clock by 1 loop cycle
	// 		cout << clock->getTime() << endl;
	// 	} else {
	// 		cout << "Nothing in ready queue" << endl;
	// 		cout << "Finished in: " << clock->getTime() << " loop cycles."<< endl;
	// 		scheduler->printQueue(scheduler->getWaitingQueue());
	// 		break;
	// 	}
	// }
	// scheduler->run();
	
	scheduler->threadTest();



}
