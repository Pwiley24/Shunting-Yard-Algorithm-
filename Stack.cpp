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
    cout << "head: " << head->getValue() << endl;
    /*
    if(checkLower(value) == false){//add to stack
      head->setNext(value);
      value->setPrevious(head);
      head = value;
    }else if(checkLower(value) == true){//remove current head and make new head
      cout << "lower remove " << value->getValue() << endl;
      value->setPrevious(head->getPrevious());
      pop();
      queue->enqueue(head);
      head = value;
    }
    */

    while(checkLower(value) == true){
      cout << "lower" << endl;
      queue->enqueue(pop());
    }
    head->setNext(value);
    value->setPrevious(head);
    head = value;
  }
}

//checks to see if added value is lower precedence
bool Stack::checkLower(Node* value){
  if(head->getValue() == 42 ||
     head->getValue() == 47 ||
     head->getValue() == 94){
    if(value->getValue() == 43 ||
      value->getValue() == 45 ||
      value->getValue() == 40 ||
      value->getValue() == 41){ //operator is lower precedence than head
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

  

 
