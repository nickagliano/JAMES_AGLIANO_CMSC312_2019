// #include libraries and packages statements
// here
// more here
// even more here

// Declare global variables
// here
// more here
// even more here


// Function to choose which algorithm to use (probably will implement via command line args)
// void chooseSchedulingAlgorithm() {
// 	switch (algorithm) {
// 		case 1:
// 			// set algorithm equal to whatever
// 			break;
// 		case 2:
// 			// set algorithm equal to whatever
// 			break;
// 		default:
// 			cout << "No matching algorithm provided" << endl;
// 			exit(EXIT_FAILURE);
// 	}
// }

// Calculate the priority of process
// int calculatePriority (string spriority) {
//
// }


// Process object
class Process {

	// Process attributes (virtual PCB)
	int pid;
	// int arrivalTime;
	// int burstTime;
	int status;
	int priority;

	// default constructor
	Process(){
		pid = 0;
		// more
		// and more
	}

	// getter
	void getProcess() {
		cout << "\nPROCESS ID : " << pid << endl;
	}

	// setter
	void setProcess(int pid1) {
		pid = pid1;
	}
};

// Dispatcher object
class Dispatcher {

		// Dispatcher attributes
		// int x;
		// int potato;

		// default constructor
		Dispatcher() {

		}

		// getter
		void getDispatcher() {
			// getter stuff
		}

		// setter
		void setDispatcher() {
			// setter stuff
		}

};

// Clock object not sure if this is needed yet
class Clock {
	// create an "abstract time" to be used by the OS
	// example, 1 "time unit" will be the atomic time unit
	//	a process could take 15 "time units" to execute
};

// ************************ PROGRAM FILE HANDLING *****************************

// interprets the input .txt files for the simulator that hold fake programs
void readProgramFile() {
	// takes "program file" text file as input

	// reads program file,
	//	interprets attributes: name, total runtime, memory,
	//	and then finally, operations (CALCULATE, I/O, etc. ... EXE)

	// generates user-specified number of processes from program file (hence randomization of values from templates must be used)

	// return a process object
}

// ***************************** ALGORITHMS ***********************************

// first come first serve scheduling algorithm
void firstComeFirstServe() {

	// declare structures
	queue<Process> readyQueue;
	queue<Process> waitingQueue;
	queue<Process> exitQueue;
	list<Process> blockedQueue;
	Process runningProcess;

	// declare variables
	int time = 0;

	// do the algorithm
}

// round robin algorithm
// void roundRobin() {
//
// }

// and other algorithms

// ****************************************************************************

// ***************************** MAIN *****************************************
int main(int argc, char**argv) {

	// create objects,
	// do simulation
}
