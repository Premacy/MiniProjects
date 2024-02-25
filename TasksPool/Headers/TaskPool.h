#pragma once

#include <vector>

#include "ITask.h"
#include "ThreadTaskSolver.h"

template<typename Task>
class TaskPool{
public:

	void run();

	void addTask( Task task );

	void addThreads(size_t threadsCount); 
	void delThreads(size_t threadsCount);

	void exit();

private:

	std::vector< ThreadTaskSolver<Task> > threads;
	std::vector< Task > 		tasks;
};