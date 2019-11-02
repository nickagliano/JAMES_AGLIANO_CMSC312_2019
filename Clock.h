#ifndef CLOCK_H
#define CLOCK_H

class Clock {
	// create an "abstract time" to be used by the OS
	// example, 1 "time unit" will be the atomic time unit
	//	a process could take 15 "time units" to execute'

	private:
		int time;

	public:
		// default constructor
		Clock();

		int getTime() { return time; }

		void start();
		void stop();

};

#endif
