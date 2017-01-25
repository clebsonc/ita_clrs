#ifndef ARRAY_OPERATIONS_
#define ARRAY_OPERATIONS_

#include <iostream>
#include <vector>

void read_values(int * const array, const int length);

void read_values(std::vector<int> & array, const int length);

void print_array(const int * const array, const int length);

void print_array(const std::vector<int> & array);

void copy_array_values(const int * const primary_array, int * const secondary_array, 
  const int lindex, const int rindex);

#endif

