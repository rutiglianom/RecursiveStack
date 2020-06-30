// Rutigliano, Matthew
// pa2.cpp
// 5/2/20

// Description: The RecursiveStack class is a simple stack with some
// recursive member functions. The constructors, push, pop, top and
// isEmpty functions all work normally, while the recInsert, print
// and printStars work recursively.

// Assumptions: 

// Sources: Dr. Kong's "formatting.txt"
//          "recPractice.cpp" by Rucha Joshi and myself

#include <iostream>
using namespace std;

#ifndef RECURSIVESTACK_H
#define RECURSIVESTACK_H

class RecursiveStack {
  private:
    
    // Node Structure
    struct Node {
      int data;
      Node* next;
    };
    
    // Head of stack
    Node* head;
  
    // Size of stack
    int stackSize;
    
    void printStars(Node*);
    // Helper function for printStars
    // Pre: RecursiveStack has been initialized
    // Post: None
    
    void print(Node*);
    // Helper function for print
    // Pre: RecursiveStack has been initialized
    // Post: None
    
  public:
    
    RecursiveStack();
    // Default Constructor
    // Pre: None
    // Post: RecursiveStack has been initialized
    
    RecursiveStack(const RecursiveStack&);
    // Copy Constructor
    // Pre: Initial RecursiveStack has been initialized
    // Post: Second RecursiveStack is now initialized, identical to the first
    
    RecursiveStack& operator=(const RecursiveStack&);
    // Overloaded Assignment Operator
    // Pre: Two RecursiveStacks have been initialized
    // Post: The two are now identical
    
    ~RecursiveStack();
    // Destructor
    // Pre: RecursiveStack has been initialized
    // Post: Memory is deallocated
    
    void push(int);
    // Pushes int onto stack
    // Pre: RecursiveStack has been initialized
    // Post: Top of stack is now int
    
    int pop();
    // Removes top of stack
    // Pre: RecursiveStack has been initialized
    // Post: Top of stack has been returned and removed, second from the
    //       top is now top. If stack is empty, -1 is returned.
    
    int top() const;
    // Returns top of stack without removing it
    // Pre: RecursiveStack has been initialized
    // Post: Top of stack has been returned
    
    bool isEmpty() const;
    // Returns true if stack is empty
    // Pre: RecursiveStack has been initialized
    // Post: True or false is returned depending on stack contents
  
    void recInsert(int);
    // Each digit of the input is pushed seperately
    // Pre: RecursiveStack has been initialized
    // Post: Each digit of the input is now on the stack
    
    void printStars();
    // Each digit on the stack is printed as stars
    // Pre: RecursiveStack has been initialized
    // Post: None
    
    void print();
    // Each digit on the stack is printed
    // Pre: RecursiveStack has been initialized
    // Post: None
};


#endif // RECURSIVESTACK_H