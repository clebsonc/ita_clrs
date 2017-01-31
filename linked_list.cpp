#include "linked_list.hpp"

LinkedList::LinkedList(){
   this->head = nullptr;
}

void LinkedList::getListNode(ListNode * & node, const int x){
  node = new ListNode(x);
}

LinkedList::~LinkedList(){
  ListNode * aux = nullptr;
  while(head!=nullptr){
    aux = head;
    head = head->getNext();
    delete aux;
  }
}

bool LinkedList::isEmpty(){
  if(head == nullptr){
    return true;
  }
  return false;
}

bool LinkedList::insert(const int x){
  ListNode * aux = nullptr;
  getListNode(aux, x);
  if(isEmpty()){
    head = aux;
    return true;
  } else{
    aux->setNext(head);
    head->setPrev(aux);
    head = aux;
    return true;
  }
  return false;
}

bool LinkedList::remove(const int x){
  ListNode * aux = head;
  while(aux != nullptr && aux->getVal() != x)
    aux = aux->getNext();
  // element x not found in the Linked List
  if(aux == nullptr)
    return false;

  // element x was found
  if(aux == head){
    head = head->getNext();
    if(head!=nullptr)
      head->setPrev(nullptr);
  } 
  else if(aux->getNext() == nullptr){
    aux->getPrev()->setNext(nullptr);
  }
  else{
    aux->getNext()->setPrev(aux->getPrev());
    aux->getPrev()->setNext(aux->getNext());
  }
  delete aux;
  return true;
}

ListNode * LinkedList::search(const int x){
  ListNode * aux = head;
  while(aux!=nullptr && aux->getVal() != x)
    aux = aux->getNext();
  return aux;
}


void LinkedList::listElements(){
  ListNode * aux = this->head;
  while(aux!=nullptr){
    std::cout << aux->getVal() << " ";
    aux = aux->getNext();
  }
  std::cout << "\n";
}

