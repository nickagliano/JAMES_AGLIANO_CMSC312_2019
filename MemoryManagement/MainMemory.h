#ifndef MAINMEMORY_H
#define MAINMEMORY_H

#include <string>
#include <queue>
#include "../ProcessManagement/Process.h"
#include "../MemoryManagement/Frame.h"
#include <list>
using namespace std;

class MainMemory {

	private:
		const static int size = 4096; // main memory size set to 4096 MB
		const static int frameSize = 16;
		const static int numFrames = 256; // total number of frames in main memory
		int numFreeFrames; // number of currently free frames
		int kernelAddressSpace; // marks end of kernal address space
		int userAddressSpace; // marks start of user address space
		Frame frameArray[numFrames];
		list<Frame> freeFrameList; // list of free frames


	public:
		// default constructor
		MainMemory();

		// no parameterized constructor needed


		// ---------------------- MEMBER FUNCTIONS ----------------------------

		// getters
		int getNumFreeFrames() { return numFreeFrames; }
		int getSize() { return size; }
		Frame getFrame(int n); // get frame at that index


		// setters
		void setNumFreeFrames(int num);
		void setFrame(int n, Frame f); // pass index and new frame for that position

		// utility funcitons
		int findFirstFit(Process process); // find frame using first fit method for a page
		int findBestFit(Process process); // find frame using best fit for a page
		void shuffle(); // to reduce external fragmentation
		
		void printFreeFrames(); // for testing

};

#endif
