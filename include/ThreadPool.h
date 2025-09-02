#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <atomic>

/*
A thread pool is a design pattern used to manage a group of worker threads that execute tasks from a shared queue.
This implementation is designed to improve performance by resuing threads for multiple tasks, avoiding the overhead of 
creating and destrouying threads repeatedly.
ThreadPool Design Purpose in order:
1. Spin up worker threads when created.
2. Allow you to submit jobs (functions/lambdas).
3. Collect results (if needed).
4. Shut down gracefully.
*/
class ThreadPool {
public: 
    // Contructor that creates a thread pool given the number of thread available
    // The word explicit ensures that the constructor is only called explicitly (when parameter is included)
    explicit ThreadPool(size_t numThreads);
    // Destructor, which ensure that all threads are joined and resources are cleaned up when they are destroyed
    ~ThreadPool();

    //submit a job, returns a future for result
    // the return std::future allows for the retrival of the results asynchronously
    /*
    Purpose: Adds a task to the task queue and notifies a worker threat to execute it
    */
    template <class F, class ... Args>
    auto submitTask(F&& f, Args&&... args) -> std::future<decltype(f(args...))>;

    /*
    Purpose:
    Makes sure that all threads in the pool complete their tasks before shutting down.
    */
    void joinAll();
private: 
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks; // the task queue

    std::mutex queueMutex; // helps prevent data races
    std::condition_variable condition; // blocks worker threads until there are tasks available or the thread is shutting down
    std::atomic<bool> stop; // signal to stop workers
};

#endif 
