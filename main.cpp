#include <iostream>
#include <string>
// #include <bits/stdc++.h>  
using namespace std;


  
struct Node { 
    int (*func)(string); 
    string param;
    struct Node* link; 
}; 
struct Node* top; 
  
// Utility function to add an element data in the stack 
 // insert at the beginning 
void push(int (*newFunc)(string), string params) { 
    // create new node temp and allocate memory 
    struct Node* temp; 
    temp = new Node(); 
  
    // check if stack (heap) is full. Then inserting an element would 
    // lead to stack overflow 
    if (!temp) { 
        cout << "\nHeap Overflow"; 
        // exit(1); 
    } 
  
    // initialize data into temp data field 
    temp->func = newFunc; 
    temp->param = params;
    // put top pointer reference into temp link 
    temp->link = top; 
  
    // make temp as top of Stack 
    top = temp; 
} 
  
// Utility function to check if the stack is empty or not 
bool isEmpty() { 
    
    return top == NULL; 
} 
  
// // Utility function to return top element in a stack 
Node *peek() { 
    // check for empty stack 
    if (!isEmpty()) {
        // cout << "not empty";
        return top; 
    }
        
    else
        return NULL;
} 
  
// Utility function to pop top  
// element from the stack 
  
void pop() { 
    struct Node* temp; 
  
    // check for stack underflow 
    if (top == NULL) { 
        // cout << "\nStack Underflow" << endl; 
        // exit(1); 
    } 
    else { 
        // top assign into temp 
        temp = top; 
  
        // assign second node to top 
        cout << top->link;
        top = top->link; 
  
        // destroy connection between first and second 
        temp->link = NULL; 
  
        // release memory of top node 
        free(temp); 
    } 
} 


int testFunc1(string param) {
    cout << " testFunc1 " << param << "\n ";
    return 0;
}

int testFunc2(string param) {
    cout << " testFunc2 " << param << "\n ";
    return 0;
}

int testFunc3(string param) {
    cout << " testFunc3 " << param << "\n ";
    return 0;
}

int secondFunc(string param) {
    cout << " second func " << param << "\n ";
    return 0;
} 

int testFunc4(string param) {
    cout << " creating second func " << param << "\n ";
    push(&secondFunc, "asdf");
    return 0;
}

int main() {

    bool keepAlive = true;
    push(&testFunc1, "asdf");
    push(&testFunc4, "fghj");
    push(&testFunc2, "qwer");
    push(&testFunc3, "zcxvx");
    

    while (keepAlive) {
        // QueueItem current = *s1.pop();
        // int res = (current.func)(current.params);
        // top.func(top.param);
        // (*top.func)->(top.param);
        Node current = *peek();
        cout << isEmpty();
        if(isEmpty() == 0) {
            current.func(current.param);
            pop();
        }
        
    }
}