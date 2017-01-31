#include "stack_array.hpp"

StackArray::StackArray(int length):SetArray(length){
}


bool StackArray::pop(int & val){
  if(size > 0){
    size--;
    val = array[size];
    return true;
  }
  return false;
}


bool StackArray::push(const int val){
  if(size < length){
    array[size] = val;
    size++;
    return true;
  }
  return false;
}


bool StackArray::top(int & val){
  if(size ==  0)
    return false;
  val = array[size-1];
  return true;
}

StackArray::~StackArray(){
}

