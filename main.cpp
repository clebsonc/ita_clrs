#include <iostream>
#include <new>
#include <cstdlib>
#include <exception>
#include <climits>

#include "queue_array.hpp"



int main(){
  QueueArray qa(6);
  
  qa.enqueue(10);
  qa.enqueue(20);
  qa.enqueue(30);
  qa.enqueue(40);
  qa.enqueue(50);
  qa.enqueue(60);


  int b = 0;
  qa.dequeue(b);
  std::cout << b << std::endl;
  qa.dequeue(b);
  std::cout << b << std::endl;
  qa.dequeue(b);
  std::cout << b << std::endl;

  qa.enqueue(70);

  std::cout << qa.getBegin() << " " << qa.getEnd() << std::endl;
  std::cout << qa.getSize() << std::endl;

  return 0;
}

