#include "sort.hpp"

void  Sort::insertion_sort(int * const vet, const int length){
  for(int i  = 1; i<length; i++){
    int key = vet[i];
    int j = i - 1;
    while(j >= 0 && vet[j] > key){
      vet[j+1] = vet[j];
      j--;
    }
    vet[j+1] = key;
  }
}


void Sort::insertion_sort_decreasing(int * const vet, const int length){
  for(int i = (length-2); i >= 0; i--){
    int key = vet[i];
    int j = i + 1;
    while(j <= (length-1) && vet[j] > key){
      vet[j-1] = vet[j];
      j++;
    }
    vet[j-1] = key;
  }
}

void Sort::merge_sort(int * const array, const int lindex, const int rindex){
  if(lindex < rindex){
    int middle = (lindex + rindex)/2;
    merge_sort(array, lindex, middle);
    merge_sort(array, middle+1, rindex);
    combine(array, lindex, middle, rindex);
  }
}


void Sort::combine(int * const array, 
    const int lindex, const int middle, const int rindex){
  int *left = nullptr, *right = nullptr;
  int nleft = middle - lindex+1;
  int nright = rindex - middle;
  
  try{
    left = new int[nleft];
    right = new int[nright];
  } catch(const std::bad_alloc & ba){
    std::cout << "Error allocating memory. \n" << ba.what();
    return;
  }
  copy_array_values(array, left, lindex, middle);
  copy_array_values(array, right, middle+1, rindex);

  int i = lindex; // index for the original array;
  int j = 0; // index for the left half; the new array
  int k = 0; // index for the right half; the new array

  while(i <= rindex){
    if(j == nleft || k == nright){
      break;
    }
    if(left[j] < right[k]){
      array[i] = left[j];
      j++;
    } else{
      array[i] = right[k];
      k++;
    }
    i++;
  }

  while(j < nleft){
    array[i] = left[j];
    i++;
    j++;
  }
  while(k < nright){
    array[i] = right[k];
    i++;
    k++;
  }

  delete[] left;
  delete[] right;
}

