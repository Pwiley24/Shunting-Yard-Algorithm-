#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(){
  value = NULL;
  next = NULL;
  previous = NULL;
}

Node::~Node(){
  delete &value;
  next = NULL;
  previous = NULL;
}

//Sets the value of the node to a char
void Node::setValue(char newVal){
  value = newVal;
}

//Returns the value of a char in a node
char Node::getValue(){
  return value;
}

//Sets the next node
void Node::setNext(Node* newNext){
  next = newNext;
}

//Returns the next node
Node* Node::getNext(){
  return next;
}

//Sets the previous node
void Node::setPrevious(Node* newPrev){
  previous = newPrev;
}

//Returns the previous node
Node* Node::getPrevious(){
  return previous;
}
