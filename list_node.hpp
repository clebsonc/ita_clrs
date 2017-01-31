#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

#include <iostream>

class ListNode{
  private:
    int val;
    ListNode * next;
    ListNode * prev;
  public:
    ListNode();
    ListNode(const int val);

    // getters and setters
    int getVal();
    void setVal(const int val);
    ListNode * getNext();
    ListNode * getPrev();
    void setNext(ListNode * p);
    void setPrev(ListNode * p);
};

#endif
