#include <iostream>
#include <cstdlib>
#include <climits>
#include "heap.hpp"


void Heap::build_heap(){
  try{
    this->array = new int[length];
  } catch(const std::bad_alloc & ba){
    std::cout << "Error allocating memory." << std::endl;
    std::cout << ba.what();
    std::exit(EXIT_FAILURE);
  }
}


void Heap::swap(const int index1, const int index2){
  int temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
}


Heap::Heap(){
  this->length = 100;
  this->size = 0;
  build_heap();
}


Heap::Heap(int length){
  this->length = length;
  this->size = 0;
  build_heap();
}


void Heap::insert(const int x){
  if(size < length){
    std::cout << "ins: " << x << std::endl; 
    size++;
    array[size-1] = x;
    int parent = size/2-1;
    int child = size - 1;
    while(parent >= 0 && array[parent] < array[child]){
      swap(parent, child);
      child = parent;
      parent = (parent%2 == 0 ? parent/2-1 : parent/2);
    }
  }
}


bool Heap::maximum(int & maximum){
  if(size > 0){
    maximum = array[0];
    return true;
  }
  std::cout << "The heap is empty " << std::endl;
  return false;
}


void Heap::heapify(const int index){
  int left = 0;
  int right = 0;
  int larger = 0;
  int i = index;
  while(i < size/2){
    left = 2*i+1;
    right = 2*i+2;
    larger = i;
    if(left < size && array[left] > array[larger]){
      larger = left;
    }
    if(right < size && array[right] > array[larger]){
      larger = right;
    }
    if(i != larger){
      swap(i, larger);
      i = larger;
    } else{
      break;
    }
  }
}


bool Heap::extract_maximum(int & maximum){
  if(size == 0){
    std::cout << "The heap is empty" << std::endl;
    return false;
  }
  maximum = array[0];
  array[0] = array[size-1];
  size--;
  heapify(0);
  return true;
}


void Heap::print_heap(){
  if(size > 0){
    for(int i = 0; i < this->size; i++){
      std::cout << array[i] << " ";
    }
    std::cout << "\n";
  }
}


int Heap::getSize(){
  return this->size;
}


int Heap::getLength(){
  return this->length;
}


Heap::~Heap(){
  delete[] array;
}
