#include "queue_array.hpp"

QueueArray::QueueArray(){
  this->begin = 1;
  this->end = 0;
}

QueueArray::QueueArray(int length):SetArray(length){
  this->begin = 1;
  this->end = 0;
}

QueueArray::~QueueArray(){
}

bool QueueArray::enqueue(const int val){
  if(this->size == this->length){
    std::cout << "The queue is full." << std::endl;
    return false;
  } else {
    this->end = (this->end+1)%this->length;
    array[this->end] = val;
    size++;
    return true;
  }
}

  bool QueueArray::dequeue(int & val){
  if(this->size == 0){
    std::cout << "The queue is empty." << std::endl;
    return false;
  } else{
    val = array[this->begin];
    this->begin = (this->begin+1)%this->length;
    this->size--;
    return true;
  }
}

int QueueArray::getEnd(){
  return this->end;
}

int QueueArray::getBegin(){
  return this->begin;
}


