#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue(){
  qhead = NULL;
  tail = NULL;
}



//adds a node to the back
void Queue::enqueue(Node* value){
  cout << "enqueue: " << value->getValue() << endl;
 if(value != NULL){
  if(qhead == NULL){//first value to queue 
    qhead = value;
    qhead->setNext(NULL);
    qhead->setPrevious(NULL);
    tail = qhead;
  }else{
    value->setPrevious(tail);
    value->setNext(NULL);
    tail->setNext(value);
    tail = value;
  }
 }
}
//removes the node from the front
Node* Queue::dequeue(){
  if(qhead != NULL){//if there is a value
    Node* temp = qhead; 
    qhead = qhead->getNext();
    return temp;
  }
  return NULL;
}

Node* Queue::peek(){
  return qhead;
}

void Queue::clear(){
  if(qhead != NULL){
    qhead->setNext(NULL);
    qhead->setPrevious(NULL);
    qhead = NULL;
  }
  if(tail != NULL){
    tail->setNext(NULL);
    tail->setPrevious(NULL);
    tail = NULL;
  }
}
