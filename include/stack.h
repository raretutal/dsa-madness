#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
public:
    virtual ~Stack() {}

    virtual void push(T x) = 0;
    virtual T pop() = 0;
    virtual T top() = 0;

    virtual int size() = 0;
    virtual bool isEmpty() = 0;
};

#endif