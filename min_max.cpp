#include <iostream>
#include <utility>
#include <array>


#include "read_values.hpp"


std::pair<int, int> min_max(std::vector<int> & array){
  std::pair<int, int> mm_(array.at(0), array.at(0));
  for(int i = 1; i < array.size(); i++){
    if(array.at(i) < mm_.first)
      mm_.first = array.at(i);
    else if(array.at(i) > mm_.second)
      mm_.second = array.at(i);
  }
  return mm_;
}

std::pair<int, int> improved_min_max(std::vector<int> & array){
  std::pair<int, int> mm_(array.at(0), array.at(0));
  bool is_odd = (array.size()%2 == 0 ? false : true);
  if(is_odd){
    array.push_back(array.back());
  }
  for(int i = 3; i< array.size(); i=i+2){
    if(array.at(i) > array.at(i-1)){
      if(array.at(i) > mm_.second)
        mm_.second = array.at(i);
      if(array.at(i-1) < mm_.first)
        mm_.first = array.at(i-1);
    } else{
      if(array.at(i) <  mm_.first)
        mm_.first = array.at(i);
      if(array.at(i-1) > mm_.second)
        mm_.second = array.at(i-1);
    }
  }
  if(is_odd)
    array.pop_back();
  return mm_;
}


int main(){
  int length = 0;
  std::cin >> length;

  std::vector<int> array(length);
  read_values(array, length);

  std::pair<int, int> pair = min_max(array);
  std::cout << "Min: " << pair.first << " Max: " << pair.second << std::endl;
  pair = improved_min_max(array);
  std::cout << "Min: " << pair.first << " Max: " << pair.second << std::endl;

  return 0;
}
