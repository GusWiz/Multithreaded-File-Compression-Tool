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

class ThreadPool {
public: 
    explicit ThreadPool(size_t numThreads);
    ~ThreadPool();
    template <class F, class ... Args>
    auto submitTask(F&& f, Args&&... args) -> std::future<decltype(f(args...))>;

    void joinAll();
private: 
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queueMutex;
    std::condition_variable condition;
    std::atomic<bool> stop;
};

#endif 
