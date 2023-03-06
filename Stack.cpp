#include <iostream>
# include "Stack.h"

using namespace std;

Stack::Stack(){
  head = NULL;
}

//Add a node to the top of the list
void Stack::push(Node* value){
  if(head == NULL){ //first data in stack
    head = value;
  }else{
    head->setNext(value);
    value->setPrevious(head);
    head = value;
  }
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

}

void Stack::print(Node* current){
  if(current == NULL){
    current = head;
    cout << head << " " << endl;
  }else{
    cout << current << " " << endl;
    if(current->getPrevious() != NULL){
      print(current->getPrevious());
    }
  }
  
}
