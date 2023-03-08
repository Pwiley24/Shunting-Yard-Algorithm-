#include <iostream>
#include <cstring>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main(){
  char input[20];
  int length = 20;
  
  //Stack List:
  Queue* queue = new Queue();
  Stack* stack = new Stack(queue);


  //Queue List:
  Node* tail;
  Node* headQ;

  cout << "enter expression" << endl;
  cin.get(input, 20);
  cin.ignore(20, '\n');
  length = strlen(input);
  cout << "lendg: " << length << endl;

  for(int i = 0; i < length; i++){
    //iterate through each input value
    //add to the stack or queue depending on input
    //number = queue
    //operation = stack (with pemdas)
    if(input[i] >= 48 &&
	input[i] <= 57){//add to queue

    }else if((input[i] >= 40 &&
	      input[i] <= 43) ||
	     (input[i] == 47) ||
	     (input[i] == 94) ||
	     (input[i] == 45)){//add to stack
      Node* newNode = new Node();
      newNode->setValue(input[i]);
      stack->push(newNode);
    }else{
      cout << "nothing" << endl;
    }
  }


  stack->print(NULL);
  
}
