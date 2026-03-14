#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
public:
    virtual ~Queue() {}

    virtual void add(T x) = 0;     // enqueue
    virtual T remove() = 0;        // dequeue
    virtual T peek() = 0;

    virtual int size() = 0;
    virtual bool isEmpty() = 0;
};

#endif