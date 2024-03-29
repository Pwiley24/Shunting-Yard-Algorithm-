#include <iostream>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree(){
  head = NULL;
}

//add to stack
void BinaryTree::push(Node* value){
  if(head != NULL){
    head->setNext(value);
    value->setPrevious(head);
    head = value;
  }else{
    head = value;
  }
}


void BinaryTree::pop(){
  if(head != NULL){
    Node* temp = head;
    if(head->getPrevious() != NULL){
      head = head->getPrevious();
      head->setNext(NULL);
      temp->setNext(NULL);
      temp->setPrevious(NULL);
    }else{
      head = NULL;
    }
  }
}

Node* BinaryTree::peek(){
  return head;
}
