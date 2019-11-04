#include "Clock.h"
#include "ProcessManagement/Process.h"
#include "ProcessManagement/Scheduler.h"

#include <iostream>
using namespace std;

// Default constructor
Clock::Clock() {
	this->time = 0;
}

void Clock::start() {

}

void Clock::stop() {

}

void Clock::step() {
	this->time++;
}
