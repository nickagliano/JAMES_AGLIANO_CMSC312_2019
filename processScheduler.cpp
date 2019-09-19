// #include libraries and packages statements
// here
// more here
// even more here

// Declare global variables

// Function to choose which algorithm to use
void chooseSchedulingAlgorithm() {
	switch (algorithm) {
		case 1 :
			// set algorithm equal to whatever
			break;
		case 2:
			// set algorithm equal to whatever
			break;
		default:
			cout << "No matching algorithm provided" << endl;
			exit(EXIT_FAILURE);
	}
}

// Calculate the priority of process
int calculatePriority (string spriority) {

}


// Process object
struct PROCESS {

	// Process attributes
	int pid;
	int status;
	int priority;

	// default constructor
	PROCESS(){
		pid = 0;
		// more
		// and more
	}

	// getter
	void getPROCESS() {
		cout << "\nPROCESS ID : " << pid << endl;
	}

	// setter
	void setPROCESS(int pid1) {
		pid = pid1;
	}
}

// ***************************** ALGORITHMS ***********************************

// first come first serve scheduling algorithm
void firstComeFirstServe() {

	// declare structures
	queue<PROCESS> readyQueue;
	queue<PROCESS> waitingQueue;
	queue<PROCESS> exitQueue;
	list<PROCESS> blockedQueue;
	PROCESS runningProcess;

	// declare variables
	int time = 0;
}

// round robin algorithm
void roundRobin() {

}
// ****************************************************************************
