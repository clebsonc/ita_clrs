#ifndef HEAP_HPP_
#define HEAP_HPP_

#include <new>
#include <exception>
#include <iostream>

class Heap{
  private:
    // maximum number of elements that the heap can maintain
    int length;
    
    // current size of heap
    int size;

    // pointer to array containing the heap datastructure
    int * array;

    // build the array structure to hold the data
    void build_heap();

    // exchange the elements of two index in the array
    void swap(const int index1, const int index2);

  public:
    // Default constructor that initializes the buffer with the size of 0;
    Heap();

    // Initializes the array with a given maxium value
    Heap(int length);
  
    
    // insert a new element into the heap
    void insert(const int x);

    // return the max element of the heap
    bool maximum(int & maximum);

    // Maintains the heap property
    void heapify(const int index);
    
    // remove and remove the maximum element of the heap
    bool extract_maximum(int & maximum);
    
    // print the elements in the heap
    void print_heap();




    //Getters 
    int getSize();
    int getLength();
    
    
    
    // Destructor responsible for the deallocating the memory
    ~Heap();
};


#endif 


