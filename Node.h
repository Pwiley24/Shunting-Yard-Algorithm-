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

  char value;
  Node* next;
  Node* previous;


};

#endif
  
