#include <iostream>
#ifndef DYNAMIC_ARRAY_INTERFACE_H
#define DYNAMIC_ARRAY_INTERFACE_H

class DynamicArrayInterface {
public:
    virtual ~DynamicArrayInterface() = default;
    virtual void append(unsigned char value) = 0;
    virtual unsigned char get(int index) const = 0;
    virtual void set(int index, unsigned char value) = 0;
    virtual int size() const = 0;
    virtual DynamicArrayInterface* add(const DynamicArrayInterface& other) const = 0;
    virtual DynamicArrayInterface* subtract(const DynamicArrayInterface& other) const = 0;
    virtual bool equals(const DynamicArrayInterface& other) const = 0;
    virtual bool lessThan(const DynamicArrayInterface& other) const = 0;
    virtual bool greaterThan(const DynamicArrayInterface& other) const = 0;
    virtual DynamicArrayInterface* copy() const = 0;
};

#endif
