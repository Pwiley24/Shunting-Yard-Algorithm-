#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "Node.h"

using namespace std;

class Queue{
 public:
  Queue();
  void enqueue(Node* value);
  Node* dequeue();
  void clear();
  Node* peek();
  Node* qhead;
  Node* tail;
};

#endif
