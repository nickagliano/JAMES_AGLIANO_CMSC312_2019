#include "ProgramFileRandomizer.h"
#include <iostream>
using namespace std;

#include <fstream> // for file writing
#include <cstdlib> // for random value generation
#include <time.h> // for assisting with random values


// need to add critical section to randomizer
void ProgramFileRandomizer::randomize() {

	srand(time(0)); // random seed based on time

	// randomly generate total runtime and memory values
	int totalRuntime = ((rand() % 10) + 1) * 100; // random value between 1 and 1000
	int numInstructions = (rand() % 30) + 3; // random value between 3 and 32
	int memory = (numInstructions * 5) + 5; // each instruction is 5 memory, + exe instruction is another 5

	// open output file
	ofstream myfile;
	myfile.open ("programFiles/random.txt");

	// Assign program file header information
	myfile << "Name: ProgramName\n";
	myfile << "Total runtime: " << totalRuntime << "\n";
	myfile << "Memory: " << memory <<"\n";
	myfile << "\n";

	// randomly generate sequence of instructions

	for (int i = 0; i <= numInstructions; i++) {

		int flag = (rand() % 10) + 1; // random value between 1 and 10

		// random value between (4 and 20) * 5,
		//	AKA random value between 20 and 100 in increments of 5
		int randValue = (((rand() % 17) + 4) * 5);

		if (flag >= 5) {
			myfile << "CALCULATE " << randValue <<"\n";
		} else {
			myfile << "I/O " << randValue <<"\n";
		}
	}

	// end and close file
	myfile << "EXE";
	myfile.close();
}
