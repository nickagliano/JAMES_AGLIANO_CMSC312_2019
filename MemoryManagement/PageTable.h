#ifndef PAGETABLE_H
#define PAGETABLE_H

// PageTable object
class PageTable{

	private:
		int pid; // which process the PageTable belongs to

	public:
		PageTable();
		PageTable(int pid);

		// getters
		int getPid() { return pid; }

		// setters
		void setPageTable(int pid, int status, int priority, int burstTime);
		void setPriority(int priority);

		// print
		void printPageTable();

};

#endif
