#pragma once

#include <chrono>

class IStopWatch{
public:
	virtual void start(void) = 0;
	virtual void stop (void)  = 0;
};

using duration_t = std::chrono::milliseconds;

class StopWatch : public IStopWatch{
public:

	//using duration_t = std::chrono::duration<double>;
	using time_t 	 = std::chrono::time_point<std::chrono::steady_clock>;

	void start(void) override;
	void stop (void)  override;

	duration_t timeElapsed(void) const;

private:

	time_t startTime;
	duration_t elapsedT;

};