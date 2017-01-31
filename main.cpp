#include <iostream>
#include <new>
#include <cstdlib>
#include <exception>
#include <climits>

#include "linked_list.hpp"


int main(){
  LinkedList a;
  a.insert(10);
  a.insert(20);
  a.insert(30);

  ListNode * b = a.search(20);
  std::cout << "s: " << (*b).getVal() << " " << (*(*b).getNext()).getVal() << 
    " " << (*(*b).getPrev()).getVal() << std::endl;
  a.remove(50);
  a.remove(20);
  a.remove(10);
  a.remove(30);
  
  a.remove(40);

  a.listElements();
  return 0;
}

