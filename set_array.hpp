#ifndef SET_ARRAY_HPP_
#define SET_ARRAY_HPP_

#include <new>
#include <exception>
#include <cstdlib>
#include <iostream>

class SetArray{
  protected:
    int * array;
    int length;
    int size;

    void build_array();

  public:
    // Default constructor
    SetArray();

    // Constructor
    SetArray(int lenght);
    
    // Destructor
    ~SetArray();
    
    // Getters
    int getSize();
    int getLength();
};


#endif
