#ifndef PAGETABLE_H
#define PAGETABLE_H

#include <string>
#include <queue>
#include <list>
using namespace std;

class PageTable {

	private:
		int pid; // pid of process that page table belongs to
		int numPages;
		int table[];

	public:
		// default constructor
		PageTable(int pid, int numPages);

		// no parameterized constructor needed


		// ---------------------- MEMBER FUNCTIONS ----------------------------

		// getters
		int getPid() { return pid; }


		// setters
		void setPid(int n); // pass index and new frame for that position
		
		
		// utility
		void print(); // pass index and new frame for that position
		

};

#endif
