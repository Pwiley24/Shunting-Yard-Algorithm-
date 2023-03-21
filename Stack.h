#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Node.h"
#include "Queue.h"

using namespace std;

class Stack{
 public:
  Stack(Queue* q);
  void push(Node* value);
  void clear();
  Node* pop();
  Node* peek();
  bool checkParenth(Node* value);
  bool checkLower(Node* value);
  Node* head;
  Queue* queue;
};
#endif
