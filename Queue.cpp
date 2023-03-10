#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue(){
  head = NULL;
  tail = NULL;
}

//adds a node to the back
void Queue::enqueue(Node* value){
  if(head == NULL){//first value to queue
    head = value;
  }else{
    if(tail == NULL){//second value to queue
      tail = value;
      head->setNext(value);
      tail->setPrevious(head);
    }else{
      value->setPrevious(tail);
      tail->setNext(value);
      tail = value;
    }
  }
}

//removes the node from the front
void Queue::dequeue(){
  if(head != NULL){//if there is a value 
    head = head->getNext();
  }
}

//print node starting from front to back
void Queue::print(Node* current){
  if(current == NULL){
    current = head;
  }
  cout << current->getValue() << " ";
  if(current->getNext() != NULL){
    print(current->getNext());
  }else{
    cout << " " << endl;
  }
  
}
