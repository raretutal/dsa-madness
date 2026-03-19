#ifndef DEQUE_H
#define DEQUE_H
 
template <typename T>
class Deque {
    public:
        virtual ~Deque() {}
 
        virtual void pushFront(T x) = 0;
        virtual void pushBack(T x) = 0;
        virtual T popFront() = 0;
        virtual T popBack() = 0;
        virtual T peekFront() const = 0;
        virtual T peekBack() const = 0;
 
        virtual int size() const = 0;
        virtual bool isEmpty() const = 0;
};
 
#endif