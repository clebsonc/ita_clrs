#include "sort.hpp"

void Sort::swap(int * const array, const int index1, const int index2){
  int temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
}

void Sort::max_heapify_iterative(int * const array, const int size, 
const int index){
  int left = 0;
  int right = 0;
  int larger = 0;
  int i = index;
  while(i<size/2){
    left = 2*i+1;
    right = 2*i+2;
    larger = i;
    if(left < size && array[larger] < array[left]){
      larger = left;
    }
    if(right < size && array[larger] < array[right]){
      larger = right;
    }
    if(larger != i){
      swap(array, i, larger);
      i = larger;
    } else{
      break;
    }
  }
}


void Sort::min_heapify_iterative(int * const array, const int size,
const int index){
  int left = 0;
  int right = 0;
  int smaller = index;
  int i = index;
  while(i < size/2){
    smaller = i;
    left = 2*i+1;
    right = 2*i+2;
    if(left < size && array[left] < array[smaller])
      smaller = left;
    if(right < size && array[right] < array[smaller])
      smaller = right;
    if(i!=smaller){
      swap(array, i, smaller);
      i = smaller;
    } else{
      break;
    }
  }
}


void Sort::build_min_heap(int * const array, int size){
  for(int i = size/2-1; i>=0; i--){
    min_heapify_iterative(array, size, i);
  }
}

void Sort::build_max_heap(int * const array, int size){
  for(int i = (size/2-1); i>=0; i--){
    max_heapify_iterative(array, size, i);
  }
}


void Sort::heap_sort_min(int * const array, const int size){
  build_min_heap(array, size);
  int index = size;
  for(int i = size-1; i>=1; i--){
    swap(array, 0, i);
    index--;
    min_heapify_iterative(array, index, 0);
  }
}

void Sort::heap_sort_max(int * const array, const int size){
  build_max_heap(array, size);
  int modified_index = size;
  for(int i = modified_index-1; i>=1; i--){
    swap(array, 0, i);
    modified_index--;
    max_heapify_iterative(array, modified_index, 0);
  }
}


void Sort::bubble_sort(int * const array, const int length){
  int temp = 0;
  for(int i = 0; i<length-1; i++){
    for(int j = length-1; j>i; j--){
      if(array[j] < array[j-1]){
        temp = array[j];
        array[j] = array[j-1];
        array[j-1] = temp;
      }
    }
  }
}


void  Sort::insertion_sort(int * const array, const int length){
  for(int i  = 1; i<length; i++){
    int key = array[i];
    int j = i - 1;
    while(j >= 0 && array[j] > key){
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = key;
  }
}


void Sort::insertion_sort_decreasing(int * const array, const int length){
  for(int i = (length-2); i >= 0; i--){
    int key = array[i];
    int j = i + 1;
    while(j <= (length-1) && array[j] > key){
      array[j-1] = array[j];
      j++;
    }
    array[j-1] = key;
  }
}


void Sort::recursive_insertion_sort(int * const array, const int length){
  if(length==1){
    return;
  }
  recursive_insertion_sort(array, length-1);
  int key = array[length-1];
  int j = length - 2;
  while(j>=0 && array[j]>key){
    array[j+1] = array[j];
    j--;
  }
  array[j+1] = key;
}


void Sort::selection_sort(int * const array, const int length){
  int k=0;
  for(int i=0; i< length-2; i++){
    k = i;
    for(int j=i+1; j<length; j++){
      if(array[j] < array[k]){
        k=j;
      }
    }
    int temp = array[i];
    array[i] = array[k];
    array[k] = temp;
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


int Sort::median_of_three(const int a, const int b, const int c){
  int m = 0;
  if(a < b && a < c)
    m = (b < c ? b : c);
  else if(b < a && b < c)
    m = (a < c ? a : c);
  else
    m = (a < b ? a : b);
  return m;
}


void Sort::quick_sort(int * array, const int lindex, const int rindex){
  if(lindex < rindex){
    int m = array[(lindex+rindex)/2];
    int pivot = median_of_three(array[lindex], m, array[rindex]);
    int i = lindex;
    int j = rindex;
    while(i < j){
      while(i < j && array[i] < pivot)
        i++;
      while(i < j && array[j] > pivot)
        j--;
      if(i < j)
        Sort::swap(array, i, j);
    }
    quick_sort(array, lindex, i-1);
    quick_sort(array, j+1, rindex);
  }
}

