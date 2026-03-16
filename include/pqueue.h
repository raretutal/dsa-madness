#ifndef PQUEUE_H
#define PQUEUE_H

template <typename T>
class PQueue {
public:
    virtual ~PQueue() {}

    virtual void add(T x) = 0;
    virtual T remove() = 0;
    virtual T peek() = 0;

    virtual int size() = 0;
    virtual bool isEmpty() = 0;
};

#endif