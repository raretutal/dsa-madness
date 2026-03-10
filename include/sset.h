// include/sset.h
#ifndef SSET_H
#define SSET_H

template <typename T>
class SSet {
public:
    virtual ~SSet() {}
    
    // Returns true if the element was added, false if it was already in the set
    virtual bool add(T x) = 0;
    
    // Returns true if the element was removed, false if it wasn't found
    virtual bool remove(T x) = 0;
    
    // Returns true if the set contains the element
    virtual bool contains(T x) const = 0;
    
    // Returns the number of elements in the set
    virtual int size() const = 0;
};

#endif 