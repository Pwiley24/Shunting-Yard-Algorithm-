#ifndef BINARYTREE_H
#define BINARYTREE_HH
#include <iostream>
#include "Node.h"

using namespace std;

class BinaryTree{
 public:
  void pop();
  Node* peek();
  void push(Node* value);
  BinaryTree();
  
  Node* head;
};
#endif
