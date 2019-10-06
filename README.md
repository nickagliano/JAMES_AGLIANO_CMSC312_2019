# CMSC 312 -- Introduction to Operating Systems
## Operating System Simulator in C++

<!-- (email from Bartosz)

	Dear Students,

	On Blackboard you will find an example template for a program file. This is just a suggestion, showing that each instruction should have assigned an individual time quantum required for its completion. At this point instructions do not have individual memory requirements, this will change when we will move to virtual memory.

	The requirements for project part 1 (deadline October 6th) are as follows:

	+ having at least 4 of your own program file templates
	+ having a procedure that reads these program files and generates user-specified number of processes from them (hence randomization of values from templates must be used)
	+ assigning a PCB to each process that stores basic metadata, including process state
	+ having a single scheduler that optimizes the process running cycle
	+ having a dispatcher that changes the status of each process in real time

	All of this must be within a single application, not multiple separate modules. -->

---

### Development Notes
- Randomize run time, number of instructions, order of instructions for the program files

- Start with first come first serve algorithm, and if functioning, work on round robin

---

# *Main class*
- runs the OS

#### Subclasses
- n/a
-

#### Functions / Methods
- n/a

#### To-do
- n/a

---

# *Scheduler class*
- the scheduler of the OS

#### Subclasses
- n/a


#### Functions / Methods
- n/a

#### To-do
- fix firstComeFirstServe() so that it is doing everything it needs to do within it's own scope/container, not in the run() method

---

# *Process class*

#### Subclasses
- n/a

#### Functions / Methods
- n/a

#### To-do
-

---

# *Clock class*

#### Subclasses
- n/a
-

#### Functions / Methods
- n/a

#### To-do
-

---

# *ProgramFileRandomizer class*

#### Subclasses
- n/a
-

#### Functions / Methods
- n/a

#### To-do
- add process name generator / randomizer
---
