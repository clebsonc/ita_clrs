#ifndef SORT_HPP_
#define SORT_HPP_

#include <vector>
#include <exception>
#include <new>
#include <cstdlib> 

#include "read_values.hpp"

class Sort{
  private:
    void static swap(int * const array, const int index1, const int index2);
  
    void static build_array(int * & array, const int size);

  public:
    static void max_heapify_iterative(int * const array,
      const int size,
      const int index);

    static void min_heapify_iterative(int * const array,
      const int size,
      const int index);

    static void build_min_heap(int * const array, int size);

    static void build_max_heap(int * const array, int size);

    static void heap_sort_max(int * const array, int size);

    static void heap_sort_min(int * const array, int size);
    
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
    
    static int median_of_three(const int a, 
      const int b, 
      const int c);

    static void quick_sort(int * const array,
      const int lindex,
      const int rindex);

    static void counting_sort(int * & array, 
      const int size, 
      const int k);
};

#endif 
