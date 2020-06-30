// Rutigliano, Matthew
// pa2.cpp
// 5/2/20

// Description: Testbench for the RecursiveStack class. Multiple stacks
// are created and all of their member functions are tested, with the user
// only needing to input a value for recInsert.

// Assumptions: None

// Sources: Dr. Kong's "formatting.txt"

#include <iostream>
#include "recursiveStack.h"

using namespace std;

int main(){
  
  // Default Constructor
  RecursiveStack stack;
  
  // Recursive insert
  int rec;
  cout << "Welcome. Please enter a positive integer: ";
  cin >> rec;
  stack.recInsert(rec);
  
  // Print
  cout << "Elements on the stack are:\n";
  stack.print();
  
  // Star print
  cout << "\n\nStar print:\n";
  stack.printStars();
  
  // Top
  cout << "Top of stack: " << stack.top() << endl;
  
  // Push
  cout << "Pushing 2\n";
  stack.push(2);
  cout << "Top of stack: " << stack.top() << endl;
  
  // Copy Constructor
  cout << "Copying stack to stack2\n";
  RecursiveStack stack2 = stack;
  cout << "Contents of stack 2:\n";
  stack2.print();
  cout << "Pushing 500\n";
  stack2.push(500);
  
  // Overloaded Assignment Operator:
  cout << "Setting stack equal to stack2\n";
  stack = stack2;
  cout << "Popping top of stack2: " << stack2.pop() << endl;
  cout << "Contents of stack:\n";
  stack.print();
  
  // Is Empty
  while(!stack.isEmpty()){
    cout << "Popping top of stack: " << stack.pop() << endl; 
    cout << "Is stack empty? " << stack.isEmpty() << endl;
  }
  
  // Closing
  cout << "My work here is done.\n";
  return 0;
}