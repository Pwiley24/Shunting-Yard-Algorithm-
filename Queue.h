#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "Node.h"

using namespace std;

class Queue{
 public:
  Queue();
  void enqueue(Node* value);
  void dequeue();
  void print(Node* current);
  Node* head;
  Node* tail;
};

#endif
