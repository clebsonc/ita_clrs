#ifndef QUEUE_ARRAY_HPP_
#define QUEUE_ARRAY_HPP_


#include "set_array.hpp"

class QueueArray:public SetArray{
  private:
    int end;
    int begin;

  public:
    // Default Constructor
    QueueArray();

    // Constructor
    QueueArray(int length);

    // Destructor
    ~QueueArray();

    // Queue Operations
    /** Returns true in case the enqueue is succeed, false otherwise
     * val: the value to be enqueued
     */
    bool enqueue(const int val);

    /** Returns true in case the dequeue process is succeed, false otherwise
     * val: the dequeued element of the queue
     */
    bool dequeue(int & val);

    // Getters
    int getEnd();
    int getBegin();
};


#endif

