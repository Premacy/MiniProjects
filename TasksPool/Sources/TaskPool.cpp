#include "TaskPool.h"

template<typename Task>
void TaskPool<Task>::addTask( Task task ){
	tasks.push_back(task);
}

template<typename Task>
void TaskPool<Task>::addThreads(size_t threadsCount){
	for(size_t i = 0; i <  threadsCount; i++){
		threads.push_back( ThreadTaskSolver( threads.size() + i ) );
	}
}

template<typename Task>
void TaskPool<Task>::delThreads(size_t threadsCount){

}

template<typename Task>
void TaskPool<Task>::exit(){

}

template<typename Task>
void TaskPool<Task>::run(){
	for(auto &thread : threads){
		if( !tasks.empty() ){
			if(thread.isFree() ){

			}
		}
	}
}