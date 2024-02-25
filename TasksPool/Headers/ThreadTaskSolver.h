#pragma once

#include <thread>
#include <stdlib.h> 
#include "ITask.h"

using std::size_t;

template<typename Task>
class ThreadTaskSolver{
public:

	ThreadTaskSolver(int threadId): id(threadId){};

	void run  (Task task);
    void kill ( );

	bool isFree( );

private:
	//void doTask(ITask *task);

private:

	ITask *task;
	int id;

	bool isFree_;
};