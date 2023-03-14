#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue(){
  qhead = NULL;
  tail = NULL;
}

//adds a node to the back
void Queue::enqueue(Node* value){
  cout << "enqueiing: " << value->getValue() << endl;
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

//removes the node from the front
void Queue::dequeue(){
  if(qhead != NULL){//if there is a value 
    qhead = qhead->getNext();
  }
}

//print node starting from front to back
void Queue::print(Node* current){
  if(current == NULL){
    current = qhead;
  }
  cout << current->getValue() << " ";
  dequeue();
  if(current->getNext() != NULL){
    print(current->getNext());
  }else{
    cout << " " << endl;
  }
  
}
