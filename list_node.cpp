#include "list_node.hpp"

ListNode::ListNode(){
  this->val = 0;
  this->next = nullptr;
  this->prev = nullptr;
}


ListNode::ListNode(const int val){
  this->val = val;
  this->next = nullptr;
  this->prev = nullptr;
}


int ListNode::getVal(){
  return this->val;
}


void ListNode::setVal(const int val){
  this->val = val;
}


ListNode * ListNode::getNext(){
  if(next == nullptr){
    return nullptr;
  }
  return this->next;
}


ListNode * ListNode::getPrev(){
  if(prev == nullptr){
    return nullptr;
  }
  return this->prev;
}


void ListNode::setNext(ListNode * p){
  this->next = p;
}

void ListNode::setPrev(ListNode * p){
  this->prev = p;
}

/*
//Tests
int main(){
  ListNode a(20);
  std::cout << "v: " << a.getVal() << std::endl;
  ListNode * b = new ListNode(30);
  ListNode * c = new ListNode(10);
  a.setNext(b);
  a.setPrev(c);
  std::cout << a.getNext()->getVal() << std::endl;
  std::cout << a.getPrev()->getVal() << std::endl;
  std::cout << a.getPrev()->getPrev() << std::endl;
  return 0;
}
*/
