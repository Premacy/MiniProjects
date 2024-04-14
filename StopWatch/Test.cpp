#include <iostream>
#include <chrono>
#include "StopWatch.h"

int fib(int n){
	return ( n > 1 ? ( fib(n) + fib(n - 1) ) : 1 );
}

int main(void){

	StopWatch sw;
	const int n = 100;

	sw.start();
	fib(n);
	sw.stop();

	const duration_t elapsedT = sw.timeElapsed();

	std::cout << "fib : " << elapsedT << std::endl;

	return 0;
}