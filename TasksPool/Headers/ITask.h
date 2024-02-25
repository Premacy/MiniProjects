#pragma once

class ITask{
public:
	virtual void operator()() = 0;
	virtual void setThreadId(int id) = 0;

	// virtual void getResult() = 0;
};
