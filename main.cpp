#include <iostream>
#include <new>
#include <cstdlib>
#include <exception>

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
  Sort::bubble_sort(array, length);
  print_array(array, length);

  
  //int q;
  //std::cout << "search for: ";
  //std::cin  >> q;
  //int s = Search::binary_search(array, length, q);
  //std::cout << " " << s << " " << std::endl;
  //if(s>=0)
  //  std::cout << "i: " << s << " " << array[s] << std::endl;
  //else
  //  std::cout << "Element not found" << std::endl;

    
  delete[] array;

  return 0;
}

