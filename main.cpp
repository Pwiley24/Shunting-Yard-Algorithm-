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
void printPrefixNotation(vector<char> postfix, vector<char> &prefix);

int main(){
  char input[20];
  int length = 20;
  
  Queue* queue = new Queue();
  Stack* stack = new Stack(queue);
  BinaryTree* tree = new BinaryTree();
  vector<char> postfix;
  vector<char> prefix;
  Node* root = NULL;

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
  cout << " " << endl;
  createTreeList(root, postfix, tree);   
  printInfixNotation(root);
  cout << " " << endl;
  printPrefixNotation(postfix, prefix);
  cout << " " << endl;
}


void createTreeList(Node* &root, vector<char> postfix, BinaryTree* &tree){  
  vector<char>::iterator ptr;
  for(ptr = postfix.begin(); ptr < postfix.end(); ptr++){
    Node* newNode = new Node();
    newNode->setValue(*ptr);
    cout << newNode->getValue() << endl;
    if(newNode->getValue() >= 48 &&
       newNode->getValue() <= 57){//value is a number
      tree->push(newNode);
    }else{//an operator
      if(root == NULL){
	root = newNode;
	root->setRight(tree->peek());
	tree->pop();
	root->setLeft(tree->peek());
	tree->pop();
      }else{
	newNode->setRight(tree->peek());
	tree->pop();
	newNode->setLeft(root);
	root = newNode;
      }
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

void printPrefixNotation(vector<char> postfix, vector<char> &prefix){
  vector<char>::iterator ptr;

  for(ptr = postfix.end(); ptr >= postfix.begin(); ptr--){
    prefix.push_back(*ptr);
    cout << *ptr;
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

  vector<char>::iterator ptr;
  for(ptr = postfix.begin(); ptr < postfix.end(); ptr++){
    cout << *ptr;
  }
}
