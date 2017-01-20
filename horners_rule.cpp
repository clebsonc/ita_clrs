/**
* Problem 2.3: Correctness of Horner's rule
* Page 41. Introduction to Algorithms CLRS 3rd edition
*/

#include <iostream>
#include <exception>
#include <cstdlib>
#include <climits>
#include "read_values.hpp"



int naive_polynomial1(const int * const array, const int length, const int x){
  int y = array[0];
  for(int i = 1; i< length; i++){
    int power = 1;
    // internally compute the power of x from 0 up to i;
    for(int j = 1; j <= i; j++){
      power = power * x;
    }
    y = y + array[i] * power;
  }
  return y;
}

int naive_polynomial2(const int * const array, const int length, const int x){
  int y = array[0];
  int power = 1; // any value to the power of 0 is 1
  for(int i = 1; i< length; i++){
    power = power*x;
    y = y + array[i] * power;
  }

  return y;
}

int horners_rule(const int * const array, const int length, const int x){
  int y = 0;
  for(int i = length-1; i >= 0; i--){
    y = array[i] + x*y;
  }
  return y;
}


int main(){
  int length = 0; 
  std::cin >> length;
  int * array;
  try{
    array = new int[length];
  } catch(const std::bad_alloc & ba){
    std::cerr << "Error allocating memory." << ba.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
  read_values(array, length);
  
  int x=0;
  std::cin.clear();
  std::cin.ignore(INT_MAX, '\n');
  std::cout << "X = ";
  std::cin >> x;
  std::cout << "Naive polynomial 1: " << naive_polynomial1(array, length, x) << std::endl;
  std::cout << "Naive polynomial 2: " << naive_polynomial2(array, length, x) << std::endl;
  std::cout << "Horner's rule: " << horners_rule(array, length, x) << std::endl;

  return 0;
}

