#ifndef SORT_HPP_
#define SORT_HPP_

#include "read_values.hpp"

class Sort{
  public:
    static void insertion_sort(int * const vet, 
       const int length);

    static void insertion_sort_decreasing(int * const vet, 
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
