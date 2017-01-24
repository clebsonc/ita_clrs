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



int main(){
  int length = 0;
  std::cin >> length;

  std::vector<int> array(length);
  read_values(array, length);

  std::pair<int, int> pair = min_max(array);
  std::cout << "Min: " << pair.first << " Max: " << pair.second << std::endl;

  return 0;
}
