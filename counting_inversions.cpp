#include <iostream>
#include <exception>
#include <new>

#include "read_values.hpp"

void build_array(int * & array, int length){
  try{
    array = new int[length];
  }catch(const std::bad_alloc & ba){
    std::exit(EXIT_FAILURE);
  }
}

int combine_count(int * const array, int il, int k, int ir){
  int *left=nullptr, *right=nullptr;
  int nl = k-il+1;
  int nr = ir-k;
  build_array(left, nl);
  build_array(right, nr);
  
  copy_array_values(array, left, il, k);
  copy_array_values(array, right, k+1, ir);
  
  int i = 0;
  int j = 0;
  int c = il;
  int inversions = 0;
  while(c<=ir){
    if(i >= nl || j >= nr){
      break;
    }
    if(left[i] <= right[j]){
      array[c] = left[i];
      i++;
      c++;
    } else{
      inversions += nl-i;
      array[c] = right[j];
      j++;
      c++;
    }
  }
  while(i < nl){
    array[c] = left[i];
    i++;
    c++;
  }
  while(j < nr){
    array[c] = right[j];
    j++;
    c++;
  }
  delete[] left;
  delete[] right;
  return inversions;
}

int merge_count_inversion(int * const array, const int il, const int ir){
  int inversions = 0;
  if(il < ir){
    int k = (il + ir)/2;
    inversions += merge_count_inversion(array, il, k);
    inversions += merge_count_inversion(array, k+1, ir);

    inversions += combine_count(array, il, k, ir);
  }
  return inversions;
}



int main(){
  int length=0;
  std::cin >> length;
  int *array = nullptr;

  build_array(array, length);

  read_values(array, length);
  int inv = merge_count_inversion(array, 0, length-1);
  print_array(array, length);
  std::cout << "\nInversions: \t" << inv << std::endl;

  delete[] array;

  return 0;
}
