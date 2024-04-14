#include "StopWatch.h"

void StopWatch::start(){
	startTime = std::chrono::steady_clock::now();
}

void StopWatch::stop(){
	const auto endTime = std::chrono::steady_clock::now();
	duration_t elapsedT = std::chrono::duration_cast<std::chrono::milliseconds>( startTime - endTime );
}

duration_t StopWatch::timeElapsed(void) const{
	return elapsedT;
}