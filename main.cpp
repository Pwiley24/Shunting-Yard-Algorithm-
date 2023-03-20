#include <iostream>
#include <vector>
#include <cstring>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

void postfixNotation(Stack* stack, Queue* queue, vector<char> &postfix);
void createTreeList(vector<char> &tree, vector<char> postfix);
void printInfixNotation(vector<char> tree);

int main(){
  char input[20];
  int length = 20;
  
  //Stack List:
  Queue* queue = new Queue();
  Stack* stack = new Stack(queue);
  vector<char> tree; 
  vector<char> postfix;

  //Queue List:
  Node* tail;
  Node* headQ;

  cout << "enter expression" << endl;
  cin.get(input, 20);
  cin.ignore(20, '\n');
  length = strlen(input);

  for(int i = 0; i < length; i++){
    //iterate through each input value
    //add to the stack or queue depending on input
    //number = queue
    //operation = stack (with pemdas)
    Node* newNode = new Node();
    newNode->setValue(input[i]);
    
    if(input[i] >= 48 &&
	input[i] <= 57){//add to queue
      cout << "to queue " << input[i] << endl;
      queue->enqueue(newNode);
    }else if(input[i] == 40 ||
	     input[i] == 41 ||
	     input[i] == 42 ||
	     input[i] == 43 ||
	     input[i] == 47 ||
	     input[i] == 94 ||
	     input[i] == 45){//add to stack
      cout << "to stack " << input[i] << endl;
      stack->push(newNode);
    }else{
      cout << "nothing" << endl;
    }
  }


  postfixNotation(stack, queue, postfix);
  createTreeList(tree, postfix);   
  printInfixNotation(tree);
  
}

void createTreeList(vector<char> &tree, vector<char> postfix){
  vector<char>::iterator ptr;
  for(ptr = postfix.end(); ptr >= postfix.begin(); ptr--){//iterate backward
    cout << *ptr << endl;
    tree.push_back(*ptr); 
  }
}

//print left child, parent, right child for all
void printInfixNotation(vector<char> tree){
  vector<char> infixNotation;
  char child2 = NULL;
  char optor = NULL;
  char child1 = NULL;
  vector<char>::iterator ptr;
  for(ptr = tree.end(); ptr > tree.begin(); ptr--){
    cout << "now " << *ptr << endl;
    if(*ptr >= 48 &&
       *ptr <= 57 &&
       child1 == NULL){//start of new operation
     cout << "first child" << endl;
      infixNotation.push_back('(');
      infixNotation.push_back(*ptr);
      child1 = *ptr;
    }else if(*ptr >= 48 &&
             *ptr <= 57 &&
             child2 == NULL){//other child value going through
      cout << "child2 " << *ptr << endl;
      child2 = *ptr;
    }else if(optor == NULL){//parent value going through
      optor = *ptr;
      cout << "optor " << optor << endl;
      infixNotation.push_back(optor);
      infixNotation.push_back(child2);//operand
      infixNotation.push_back(')');
      child1 = NULL;
      optor = NULL;
      child2 = NULL;
    }   
  }
  for(ptr = infixNotation.begin(); ptr < infixNotation.end(); ptr++){
    cout << *ptr;
  }
  cout << " infix " << endl;
}


void postfixNotation(Stack* stack, Queue* queue, vector<char> &postfix){
  while(queue->peek() != NULL){
    postfix.push_back(queue->dequeue()->getValue());
  }
  while(stack->peek() != NULL){
    if(stack->peek()->getValue() != 41 &&
       stack->peek()->getValue() != 40){
      postfix.push_back(stack->pop()->getValue());
    }else{
      stack->pop();
    }
  }

  vector<char>::iterator ptr;
  for(ptr = postfix.begin(); ptr < postfix.end(); ptr++){
    cout << *ptr;
  }
  cout << " " << endl;

}
