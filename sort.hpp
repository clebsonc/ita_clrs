#ifndef SORT_HPP_
#define SORT_HPP_

#include "read_values.hpp"

class Sort{
  private:
    void static swap(int * const array, const int index1, const int index2);

  public:
    static void max_heapify_iterative(int * const array,
      const int size,
      const int index);

    
    
    static void bubble_sort(int * const array, 
      const int lenght);

    static void insertion_sort(int * const array, 
       const int length);

    static void insertion_sort_decreasing(int * const array, 
      const int length);

    static void recursive_insertion_sort(int * const array,
      const int length);

    static void selection_sort(int * const array, 
      const int length);

    static void combine(int * const array, 
      const int lindex, 
      const int middle, 
      const int rindex);

    static void merge_sort(int * const array, 
      const int lindex, 
      const int rindex);
};

#endif 
