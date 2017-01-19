#include "search.hpp"

int Search::linear_search(const int * array, const int length, const int q){
  for(int i=0; i<length; i++){
    if(array[i] == q)
      return i;
  }

  return -1; // no element was found
}

int Search::binary_search(const int * const array, const int length, const int q){
  int beginning = 0, end = length-1;
  int k = (beginning + end)/2;
  while(beginning != end){
    if(array[k] == q){
      return k;
    }
    if(array[k] > q)
      end = k;
    else
      beginning = k+1;
    k = (beginning+end)/2;
  }
  if(array[k] == q)
    return k;
  return -1;
}

