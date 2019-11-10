#ifndef MAINMEMORY_H
#define MAINMEMORY_H

#include <string>
#include <queue>
// #include "../ProcessManagement/Process.h"
#include "../MemoryManagement/Frame.h"
#include <list>
using namespace std;

class MainMemory {

	private:
		const static int size = 4096; // main memory size set to 4096 MB
		const static int numFrames = 256; // total number of frames in main memory
		const static int frameSize = 16;
		int numFreeFrames; // number of currently free frames
		Frame frameArray[numFrames]; // indexed array of frames 0 - 255
		list<Frame> freeFrameList; // list of free frames

		const static int virtualSize = 8192; // virtual memory size set to 8192 MB
		const static int numVirtualFrames = 512; // total number of frames in main memory
		int numFreeVirtualFrames; // total number of frames in virtual memory

		int kernelAddressSpace; // marks end of kernal address space
		int userAddressSpace; // marks start of user address space

	public:
		// default constructor
		MainMemory();

		// no parameterized constructor needed


		// ---------------------- MEMBER FUNCTIONS ----------------------------

		// getters
		int getNumFreeFrames() { return numFreeFrames; }
		int getNumFreeVirtualFrames() { return numFreeVirtualFrames; }
		int getSize() { return size; }
		Frame getFrame(int n); // get frame at that index


		// setters
		void setNumFreeFrames(int num);
		void setNumFreeVirtualFrames(int num);
		void setFrame(int n, Frame f); // pass index and new frame for that position

		// utility funcitons
		// int findFirstFit(Process process); // find frame using first fit method for a page
		// int findBestFit(Process process); // find frame using best fit for a page
		void shuffle(); // to reduce external fragmentation

		void printFreeFrames(); // for testing

};

#endif
