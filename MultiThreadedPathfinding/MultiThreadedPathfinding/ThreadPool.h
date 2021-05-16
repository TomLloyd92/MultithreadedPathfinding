#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <iostream>
#include <thread>
#include <queue>
#include <functional>
#include <condition_variable>
#include <future>
#include <string>


class ThreadPool {
public:
	ThreadPool();
	~ThreadPool();
	void start();

	//Threads handle the que 
	void threadQue(std::function<void()> function);

private:

	//Mutex for locking the thread
	std::mutex mutex;

	//Bool to notify stopping a thread
	bool stopping = false;

	//Condition Variable to manage threads
	//Notifying other threads
	//Waiting on condition
	std::condition_variable CV;

	//Threads Vector
	//Vector that holds all threads
	std::vector<std::thread> m_threads;

	//Que of functions that will be poped and called in order
	std::queue< std::function<void()>> m_functionsQue;

	//Stop thread function and rejoin program
	void stop();

	//Amount of Cores on the CPU
	int cores = 0;
};
#endif // !THREAD_POOL_H


