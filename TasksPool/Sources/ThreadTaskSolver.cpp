#include "ThreadTaskSolver.h"

template<typename Task>
void ThreadTaskSolver<Task>::run(Task task){
	isFree_ = false;

	task->setThreadId(id);

	std::thread t((*task));
	t.join();
		
	isFree_ = true;
}

template<typename Task>
bool ThreadTaskSolver<Task>::isFree(){

}

template<typename Task>
void ThreadTaskSolver<Task>::kill(){
		
}