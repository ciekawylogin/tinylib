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
        std::cout << "dupa 1 "<< std::endl;
        std::unique_lock<std::mutex> mlock(mutex);
        std::cout << "dupa 2 "<< std::endl;
        while (queue.empty())
        {
            cond.wait(mlock);
        }
        std::cout << "dupa 4 "<< std::endl;
        Data item = queue.front();
        std::cout << "dupa 5 "<< std::endl;
        queue.pop();
        std::cout << "dupa 7 "<< std::endl;
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
