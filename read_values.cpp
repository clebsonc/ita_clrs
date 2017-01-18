#include "read_values.hpp"


void read_values(int * const array, const int length){
  for(int i = 0; i < length; i++){
    std::cin >> *(array+i);
  }
}


void read_values(std::vector<int> & array, const int length){
  for(int i = 0; i < length; i++){
    std::cin >> array.at(i);
  }
}


void print_array(const int * const array, const int length){
  for(int i = 0; i < length; i++){
    std::cout << *(array+i) << " ";
  }
  std::cout << std::endl;
}


void copy_array_values(const int * const primary_array, int * const secondary_array, 
  const int lindex, const int rindex){
  int k = 0;
  for(int i = lindex; i<=rindex; i++){
    secondary_array[k] = primary_array[i];
    k++;
  }
}

