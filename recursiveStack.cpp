// Rutigliano, Matthew
// pa2.cpp
// 5/2/20

// Description: Implementation of RecursiveStack class

// Assumptions: None

// Sources: Dr. Kong's "formatting.txt"
//          "recPractice.cpp" by Rucha Joshi and myself

#include "recursiveStack.h"

// Default Constructor
RecursiveStack::RecursiveStack() {
  head = nullptr;
  stackSize = 0;
}

// Copy Constructor
RecursiveStack::RecursiveStack(const RecursiveStack& stack){  
  head = nullptr;
  if (!stack.isEmpty()){
    push(stack.top());
    
    Node* addPtr1 = nullptr;
    Node* addPtr2 = head;
    Node* travPtr = stack.head->next;
    while(travPtr){
      addPtr1 = new Node{travPtr->data, nullptr};
      addPtr2->next = addPtr1;
      travPtr = travPtr->next;
      addPtr2 = addPtr2->next;
    }
  }
  stackSize = stack.stackSize;
}

// Overloaded Assignment Operator
RecursiveStack& RecursiveStack::operator=(const RecursiveStack& stack){
  if (&stack != this){
    while(!isEmpty())
      pop();
  
    if (!stack.isEmpty()){
      push(stack.head->data);
      
      Node* addPtr1 = nullptr;
      Node* addPtr2 = head;
      Node* travPtr = stack.head->next;
      while(travPtr){
        addPtr1 = new Node{travPtr->data, nullptr};
        addPtr2->next = addPtr1;
        travPtr = travPtr->next;
        addPtr2 = addPtr2->next;
      }
    }
    stackSize = stack.stackSize;
  }
  return *this;
}

// Destructor
RecursiveStack::~RecursiveStack(){
  while(!isEmpty())
    pop();
}

// Push
void RecursiveStack::push(int data){
  Node* newNode = new Node;
  newNode->data = data;
  
  newNode->next = head;
  head = newNode;
  stackSize++;
}

// Pop
int RecursiveStack::pop(){
  int data;
  if (isEmpty())
    data = -1;    // Empty return
  else{
    Node* tempPtr = head;
    data = tempPtr->data;
    head = head->next;
    delete tempPtr;
    stackSize--;
  }
  return data;
}

// Top
int RecursiveStack::top() const {
  int top = 0;
  if (!isEmpty())
    top = head->data;
  return top;
}

// Is Empty
bool RecursiveStack::isEmpty() const {
  return stackSize == 0;
}

// Recursive Insert
void RecursiveStack::recInsert(int n){
  if (n < 0) {
    cout << "Positive integers only!\n";
  } else if (n <= 9) {
    push(n);
  } else {
    push(n % 10);
    recInsert(n / 10);
  }
}

// Print Stars
void RecursiveStack::printStars(){
  printStars(head);
}

// Print Stars Helper Function
void RecursiveStack::printStars(Node* head){
  if (!head)
    return;
  else {
    if (head->data){
      for(int i = 0; i < head->data; i++)
        cout << "*";
    } else {
      cout << "-";
    }
    cout << endl;
    printStars(head->next);
  }
}

// Print
void RecursiveStack::print(){
  if (!isEmpty()) {
    cout << head->data;
    print(head->next);
  }
}

// Print Helper Function
void RecursiveStack::print(Node* head){
  if (!head){
    cout << endl;
  } else {
    cout << "," << head->data;
    print(head->next);
  }
}