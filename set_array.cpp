#include "set_array.hpp"


void SetArray::build_array(){
  if(this->length > 0){
    try{
      this->array = new int[length];
    }
    catch(const std::bad_alloc & ba){
      std::cerr << "Error allocating memory: " << ba.what() << std::endl;
      std::exit(EXIT_FAILURE);
    }
  }
}


SetArray::SetArray(){
  this->length = 10;
  this->size = 0;
  build_array();
}


SetArray::SetArray(const int length){
  this->length = length;
  this->size = 0;
  build_array();
}


SetArray::~SetArray(){
  delete[] array;
}


int SetArray::getSize(){
  return this->size;
}


int SetArray::getLength(){
  return this->length;
}

