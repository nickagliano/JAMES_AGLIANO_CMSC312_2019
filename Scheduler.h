#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler {

	private:
		// private variables

	public:
		// default constructor
		Scheduler();

		// parameterized constructor
		Scheduler();


		// member functions
		void firstComeFirstServe();

		void roundRobin();

		int calculatePriority();

		void readProgramFile();

};

// how to declare dispatcher object? it should probably inherit scheduler / be a subclass
// Dispatcher object
// class Dispatcher {
//
// 		// Dispatcher attributes
// 		// int x;
// 		// int potato;
//
// 		// default constructor
// 		Dispatcher() {
//
// 		}
//
// 		// getter
// 		void getDispatcher() {
// 			// getter stuff
// 		}
//
// 		// setter
// 		void setDispatcher() {
// 			// setter stuff
// 		}
//
// };


#endif
