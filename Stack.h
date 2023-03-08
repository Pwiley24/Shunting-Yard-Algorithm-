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
  Node* pop();
  void peek();
  void print(Node* current);
  bool checkLower(Node* value);
  bool checkHigher(Node* value);
  Node* head;
  Queue* queue;
};
#endif
