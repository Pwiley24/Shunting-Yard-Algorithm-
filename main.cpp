/*
 * This program takes in a mathmatical equation and converts it to
 * its prefix, postfix, or infix notation
 * Author: Paige Wiley
 * Date: 03-18-23
*/
#include <iostream>
#include <vector>
#include <cstring>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"

using namespace std;

void postfixNotation(Stack* stack, Queue* queue, vector<char> &postfix);
void createTreeList(Node* &root, vector<char> postfix, BinaryTree* &tree);
void printInfixNotation(Node* root);
void printPrefixNotation(Node* current);
void printPostfixNotation(Node* current);

int main(){
  char input[20];
  int length = 20;
  bool playing = true;
  Queue* queue = new Queue();
  Stack* stack = new Stack(queue);
  
  while(playing){
    bool sameExpression = true;
    vector<char> postfix;
    Node* root = NULL;
    BinaryTree* tree = new BinaryTree();
 
    cout << "enter expression or QUIT" << endl;
    cin.get(input, 20);
    cin.ignore(20, '\n');
    if(strcmp(input, "QUIT") != 0){
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
          queue->enqueue(newNode);
        }else if(input[i] == 40 ||
	         input[i] == 41 ||
	         input[i] == 42 ||
	         input[i] == 43 ||
	         input[i] == 47 ||
	         input[i] == 94 ||
	         input[i] == 45){//add to stack
          stack->push(newNode);
        }else{
          cout << "nothing" << endl;
        }
      }
      while(sameExpression){
	postfixNotation(stack, queue, postfix);
	vector<char>::iterator ptr;
	
	for(ptr = postfix.begin(); ptr < postfix.end(); ptr++){
	  cout << *ptr;
	}
	cout << " " << endl;
	createTreeList(root, postfix, tree);;

        cout << "View Notation (INFIX, PREFIX, POSTFIX, NEW)" << endl;
        cin.get(input, 20);
        cin.ignore(20, '\n');
    
        if(strcmp(input, "INFIX") == 0){//print infix
          cout << "Infix: ";
          printInfixNotation(root);
          cout << " " << endl;
        }else if(strcmp(input, "PREFIX") == 0){//print prefix
          cout << "Prefix: ";
          printPrefixNotation(root);
          cout << " " << endl;
        }else if(strcmp(input, "POSTFIX") == 0){
          cout << "Postfix: ";
          printPostfixNotation(root);
          cout << " " << endl;
        }else if(strcmp(input, "NEW") == 0){//ask for new expression
          queue->clear();
          stack->clear();
	  sameExpression = false;
	}
      }
    }else{//quit playing
      playing = false;
    } 
  }
}

//Prints the shunting yard algorithm
void printPostfixNotation(Node* current){
  if(current!= NULL){
    if(current->getLeft() != NULL){//still left value
      printPostfixNotation(current->getLeft());
    }
    if(current->getRight() != NULL){//still right value
      printPostfixNotation(current->getRight());
    }
    cout << current->getValue();
  }
}

void createTreeList(Node* &root, vector<char> postfix, BinaryTree* &tree){  
  vector<char>::iterator ptr;
  for(ptr = postfix.begin(); ptr < postfix.end(); ptr++){
    Node* newNode = new Node();
    newNode->setValue(*ptr);
    if(newNode->getValue() >= 48 &&
       newNode->getValue() <= 57){//value is a number
      tree->push(newNode);
    }else{//an operator
      root = newNode;
      root->setRight(tree->peek());
      tree->pop();
      root->setLeft(tree->peek());
      tree->pop();
      tree->push(newNode);
    }
  }
}



//print left child, parent, right child for all
void printInfixNotation(Node* root){
  if(root != NULL){
    if(root->getValue() == 43 ||
       root->getValue() == 42 ||
       root->getValue() == 47 ||
       root->getValue() == 94 ||
       root->getValue() == 45){//root is an operator
      cout << '(';
    }
    if(root->getLeft() != NULL){
      printInfixNotation(root->getLeft());
    }
    cout << root->getValue();
    if(root->getRight() != NULL){
      printInfixNotation(root->getRight());
    }
    if(root->getValue() == 43 ||
       root->getValue() == 42 ||
       root->getValue() == 47 ||
       root->getValue() == 94 ||
       root->getValue() == 45){//root is an operator
      cout << ')';
    }
  }
}

void printPrefixNotation(Node* current){
   if(current != NULL){
      cout << current->getValue();
      if(current->getRight() != NULL){
        printPrefixNotation(current->getRight());
      }
      if(current->getLeft() != NULL){
        printPrefixNotation(current->getLeft());
      }
   }
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
}

