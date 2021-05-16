#include "ThreadPool.h"

ThreadPool::ThreadPool() {

	//Set amount of cores
	cores = std::thread::hardware_concurrency() - 1;	
	start();

}

ThreadPool::~ThreadPool() {
	stop();
}

void ThreadPool::start()
{
	//Go through all the cores
	for (int i = 0; i < cores; i++)
	{
		m_threads.emplace_back([=]
		{
			while (true)
			{	
				//New Function that will be assigned
				std::function<void()> function;

				//CRITICAL SECTION
				{
					//Aquire the lock
					//Needed for the Condition variable to lock and wait
					std::unique_lock<std::mutex> lock{ mutex };
					
					std::cout << m_threads.at(i).get_id() << ": Proccessing" << std::endl;
		
					//Condition Variable checks the lock to see if it can proceed
					//If returns false unlock mutex
					CV.wait(lock, [=] {return ( !stopping && !m_functionsQue.empty()) ? true : false; });					
					//CV.wait(lock, [=] {return stopping || !m_functionsQue.empty(); });

					//Leave for now if we are stopping or if it is empty
					if (stopping && m_functionsQue.empty())
					{
						break;
					}
					//Assign front of the que to our function
					function = std::move(m_functionsQue.front());
					//Pop the function from the que
					m_functionsQue.pop();
					//Call the popped function
					function();
				}
				//END CRITICAL SECTION			
			}
		});
	}

}



void ThreadPool::threadQue(std::function<void()> function)
{
	m_functionsQue.emplace(std::move(function));

	//Condition variable can Notify one of the threads
	CV.notify_one();
}

void ThreadPool::stop()
{
	{
		std::unique_lock<std::mutex> lock{ mutex };
		stopping = true;
	}

	//Notify all threads to stop
	CV.notify_all();

	for (auto& thread : m_threads)
	{
		thread.join();
	}
}
