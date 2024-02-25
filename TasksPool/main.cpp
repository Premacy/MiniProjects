#include <iostream>
#include <vector>
#include <thread>

using std::size_t;

/*class TestTask : public ITask{
public:

	void setThreadId(int threadId_){
		threadId = threadId_;
	}

	void runTask(){
		for(size_t i = 0; i < 1000000; i++){
			std::cout << "Thread id = " << threadId << ", " << i << std::endl;
		}
	}

private:
	int threadId;
}*/



template<typename T>
class A{
public:
	void f();
};

template<typename T> void A<T>::f(){
	
}

int main(){

	return 0;
}