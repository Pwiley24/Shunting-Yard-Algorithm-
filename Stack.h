#include <iostream>
#include "Node.h"

using namespace std;

class Stack{
 public:
  Stack();
  void push(Node* value);
  Node* pop();
  void peek();
  void print(Node* current);
  Node* head;
};
