#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include "list_node.hpp"

class LinkedList{
  private:
    ListNode * head;
    
    void getListNode(ListNode * & node, const int x);

  public:
    // Default Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    bool isEmpty();
    bool insert(const int x);
    bool remove(const int x);
    ListNode * search(const int x);

    void listElements();

};

#endif
