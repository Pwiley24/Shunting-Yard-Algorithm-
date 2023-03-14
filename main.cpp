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

  cout << "test queu: " << endl;
  //queue->print(NULL);
  cout << "Stack: " << endl;
  stack->print(NULL);
  stack->enqueueAll(NULL);
  cout << "Queue: " << endl;
  queue->print(NULL);
  
}
