#include <iostream>
#include <exception>
#include <new>
#include <utility>
#include <climits>

#include "sort.hpp"
#include "read_values.hpp"

std::pair<int, int> pair_exists(int * const array, const int length, const int x)
{
  Sort::merge_sort(array, 0, length-1);
  int begin=0, end=0, k=0;
  if(x < (array[0] + array[1]) || x > (array[length-1] + array[length-2])){
    return std::pair<int, int>(-1, -1);
  }
  for(int i = 0; i<length-1; i++){
    begin = i+1;
    end = length-1;
    while(begin <= end){
      k = (begin + end)/2;
      if(array[i] + array[k] == x){
        return std::pair<int, int>(i, k);
      } 
      else if(array[i] + array[k] > x){
        end = k-1;
      } else{
        begin = k+1;
      }
    }
  }
}


int main(){
  int n = 0;
  std::cin >> n;
  int * array = nullptr;
  try{
    array = new int[n];
  }catch(const std::bad_alloc & ba){
    std::cerr << "Error allocating memory: \n" << ba.what();
  }

  read_values(array, n);
  int q = 0;
  std::cout << "sum: ";
  
  std::cin.clear();
  std::cin.ignore(INT_MAX, '\n');
  std::cin >> q;

  std::pair<int, int> index = pair_exists(array, n, q);
  print_array(array, n);
  std::cout << "index: ["<<index.first << ", " << index.second<<"]" << std::endl;


  delete[] array;

  return 0;
}

