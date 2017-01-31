#ifndef STACK_ARRAY_HPP_
#define STACK_ARRAY_HPP_

#include "set_array.hpp"

class StackArray:public SetArray{
  public:
    // Default constructor
    StackArray();

    // Constructor
    StackArray(int length);
    
    // Destructor
    ~StackArray();
    
    // Stack operations
    // Remove and return the top element of the stack
    bool pop(int & val);
    
    // Insert one element in the stack
    bool push(const int val);

    // Returns the last element of the stack
    bool top(int & val);

};

#endif
