#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(Queue* q){
  head = NULL;
  queue = q;
}

//Add a node to the top of the list
void Stack::push(Node* value){
  if(head == NULL){ //first data in stack
    head = value;
  }else{
    if(checkLower(value) == false &&
       checkHigher(value) == false){//add to stack
      head->setNext(value);
      value->setPrevious(head);
      head = value;
    }else if(checkLower(value) == true &&
	     checkHigher(value) == false){//remove current head and make new head
      value->setPrevious(head->getPrevious());
      pop();
      queue->enqueue(head);
      head = value;
    }else if(checkLower(value) == false &&
	     checkHigher(value) == true){//add value to queue
      queue->enqueue(value);
    }
  }
}

//checks to see if added value is lower precedence
bool Stack::checkLower(Node* value){
  if((head->getValue() == 43 ||
     head->getValue() == 47 ||
      head->getValue() == 94) &&
     (value->getValue() == 43 ||
      value->getValue() == 45 ||
      value->getValue() == 29 ||
      value->getValue() == 28)){ //operator is lower precedence than head
    return true;
  }
  return false;
}

//checks to see if added value is higher precedence
bool Stack::checkHigher(Node* value){
  if((value->getValue() == 42 ||
      value->getValue() == 47) &&
     (head->getValue() == 43 ||
      head->getValue() == 40 ||
      head->getValue() == 41 ||
      head->getValue() == 45)){//operator is multi or div and higher
    return true;
  }else if(value->getValue() == 94 &&
	   ((head->getValue() >= 40 &&
	     head->getValue() <= 43) ||
	    head->getValue() == 45 ||
	    head->getValue() == 47)){//operator is power and higher
    return true;
  }
  return false;
}

//Remove and return a node from the top of the list
Node* Stack::pop(){
  if(head != NULL){//data in stack
    Node* temp = head;
    head = head->getPrevious();
    return temp;
  }
}

void Stack::peek(){
  cout << head->getValue() << endl;
}

void Stack::print(Node* current){
  if(current == NULL){
    current = head;
    cout << head->getValue() << " ";
  }else{
    cout << current->getValue() << " ";
  }
  if(current->getPrevious() != NULL){
    print(current->getPrevious());
  }
  
}
