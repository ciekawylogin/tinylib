#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

/**
 * @brief Synchronizowana kolejka na wzór BlockingQueue z Javy.
 *
 * @TODO Uzupełnić ten opis, udokumentować metody
 */
template <typename Data>
class BlockingQueue
{
    std::queue<Data> queue;
    std::mutex mutex;
    std::condition_variable cond;
public:
    Data pop()
    {
        std::unique_lock<std::mutex> mlock(mutex);
        while (queue.empty())
        {
            cond.wait(mlock);
        }
        Data item = queue.front();
        queue.pop();
        return item;
    }

    void push(const Data& item)
    {
        std::unique_lock<std::mutex> mlock(mutex);
        queue.push(item);
        mlock.unlock();
        cond.notify_one();
    }

    // przeciążenie pozwalające poprawić wydajność (podobno)
    // && = r-value
    void push(Data&& item)
    {
        std::unique_lock<std::mutex> mlock(mutex);
        queue.push(std::move(item));
        mlock.unlock();
        cond.notify_one();
    }
};

#endif // BLOCKINGQUEUE_H
