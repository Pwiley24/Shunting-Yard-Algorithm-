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
    head->setPrevious(NULL);
    head->setNext(NULL);
  }else{
    while(checkLower(value) == true){
      queue->enqueue(pop());
    }
    if(checkParenth(value) == true){
      while(value->getValue() != 40){
       if(value->getValue() == 41){
         value = head;
       }else{
         queue->enqueue(pop());
         head->setNext(value);
         value->setPrevious(head);
         value = head;
       }
      }
    }else{
      head->setNext(value);
      value->setPrevious(head);
      head = value;
   }
  }
}

//checks to see if a left () was added
bool Stack::checkParenth(Node* value){
  if(value->getValue() == 41){//left parenthesis detected
    //enqueue until right parenthesis detected
    return true; 
  }
  return false;
}

//checks to see if added value is lower precedence
bool Stack::checkLower(Node* value){
  if(head->getValue() == 42 ||
     head->getValue() == 47){
    if(value->getValue() == 43 ||
      value->getValue() == 45){ //operator is lower precedence than head
      return true;
    }
  }else if(head->getValue() == 94){//is power
    if(value->getValue() == 42 ||
       value->getValue() == 47 ||
       value->getValue() == 43 ||
       value->getValue() == 45){
      return true;
    }
  }
  return false;
}


//Remove and return a node from the top of the list. 
//head becomes the next node
Node* Stack::pop(){
  if(head != NULL){//data in stack
    Node* temp = head;
    if(head->getPrevious() != NULL){
      head = head->getPrevious();
      head->setNext(NULL);
      temp->setNext(NULL);
      temp->setPrevious(NULL);
      return temp;
    }
    head = NULL;
    return temp;
  }
  return NULL;
}

Node* Stack::peek(){
  return head;
}

void Stack:: clear(){
  if(head != NULL){
    head->setNext(NULL);
    head->setPrevious(NULL);
    head = NULL;
  }
}

 
