#ifndef PAGETABLE_H
#define PAGETABLE_H

// PageTable object
class PageTable{

	private:
		int pid; // which process the PageTable belongs to
		int table; // first column is page num, 2nd column is frame num, 3rd column is valid/invalid bit
		// x  x  x
		// x  x  x
		// x  x  x
		// x  x  x
		// x  x  x

	public:
		PageTable();
		PageTable(int numPages);

		// getters
		int getPid() { return pid; }
		int getTable() { return table; }
		int getRow(int pageIndex) { return table[pageIndex]; }
		int getFrameIndex(int pageIndex) { return table[pageIndex][1]; }
		int getValidBit(int pageIndex) { return table[pageIndex][2]; }

		// setters
		void setFrame(int pageIndex, int frameIndex);

		// print
		void printPageTable();

};

#endif
