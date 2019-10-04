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


	Scheduler* scheduler = new class Scheduler(); // declare scheduler

	scheduler->setAlgorithm(0); // use firstComeFirstServe algorithm

	scheduler->readProgramFile("programFiles/randomFile1.txt"); // process a program file

	scheduler->printQueue(scheduler->getReadyQueue());


}
