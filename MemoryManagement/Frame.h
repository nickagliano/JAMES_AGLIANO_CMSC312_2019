#ifndef FRAME_H
#define FRAME_H

#include <string>
#include <queue>
#include <list>
using namespace std;

class Frame {

	private:
		int address; // 0 - 255 (256 frames in memory)
		bool isFree; // boolean to check if it's free or not

	public:
		// constructor
		Frame();

		// ---------------------- MEMBER FUNCTIONS ----------------------------

		// getters
		int getAddress() { return address; }
		int getIsFree() { return isFree; }

		// setters
		void setAddress(int a);
		void release() { this->isFree = true; }
		void allocate() { this->isFree = false; }

		void printAddress();


};

#endif
