#include <iostream>
#include <vector>
#include "read_values.hpp"

std::vector<int> add_two_binary_integers(std::vector<int> & array1, 
                                           std::vector<int> & array2){
  std::vector<int> array3;
  int a = 0;
  for(int i = array1.size()-1; i >= 0; i--){
    array3.emplace(array3.begin(), array1.at(i) ^ array2.at(i) ^ a);
    a = ((array1.at(i) + array2.at(i) + a) > 1 ? 1 : 0);
  }
  if(a)
    array3.emplace(array3.begin(), a);

  return array3;
}


int main(){
  int length = 0;
  std::cin >> length;
  std::vector<int> a1(length,0);
  std::vector<int> a2(length,0);

  std::cout << "array1: ";
  read_values(a1, length);
  std::cout << "array2: ";
  read_values(a2, length);

  std::vector<int> a3 = add_two_binary_integers(a1, a2);

  std::cout << "\n";
  for(auto i : a3)
    std::cout << i << " ";

  std::cout << "\n";
  return 0;
}

