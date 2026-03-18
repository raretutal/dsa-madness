#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
    public:
        virtual ~List() {}

        virtual T get(int i) const = 0;
        virtual T set(int i, T x) = 0;
        virtual void add(int i, T x) = 0; 
        virtual T remove(int i) = 0;

        virtual int size() const = 0;
        virtual bool isEmpty() const = 0;

        virtual void addFirst(T x) { add(0, x); } 
        virtual void addLast(T x) { add(size(), x); }
        virtual T removeFirst() { return remove(0); }
        virtual T removeLast() { return remove(size() - 1); }
};

#endif