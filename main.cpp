#include <iostream>
#include <new>
#include <cstdlib>
#include <exception>
#include <climits>

#include "read_values.hpp"
#include "sort.hpp"
#include "search.hpp"

int main(){
  int length=0;
  std::cin >> length;
  int *array = nullptr;

  try{
    array = new int[length];
  } catch(const std::bad_alloc & ba){
    std::cout << "Error allocating memory.\n" << ba.what();
    std::exit(EXIT_FAILURE);
  }

  read_values(array, length);
  Sort::heap_sort_min(array, length);
  print_array(array, length);
  
  
  delete[] array;

  return 0;
}

