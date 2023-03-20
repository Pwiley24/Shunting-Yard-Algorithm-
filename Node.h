#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node {
 public:
  Node();
  ~Node();
  void setValue(char newVal);
  char getValue();
  Node* getNext();
  void setNext(Node* newNext);
  void setPrevious(Node* newPrev);
  Node* getPrevious();
  Node* getRight();
  Node* getLeft();
  void setRight(Node* newRight);
  void setLeft(Node* newLeft);
  
  char value;
  Node* next;
  Node* previous;
  Node* left;
  Node* right;

};

#endif
  
