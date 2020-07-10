// File Name: Stack.h
//
// Author: Archana Sridhar
// Date: 4/22/2019
// Assignment Number: 6
// CS 5301 Spring 2019
// Instructor: Dr.Jill Seaman
//
//  A linked list of string to implement the stack operations.

#ifndef Stack_h
#define Stack_h
#include <string>
using namespace std;

class Stack
{
    private:
    struct Node
    {
        string value;
        Node* next;
    };
    Node* head;
    
    public:
    //**************************************************************
    // This constructor creates an empty stack of a specified size.
    //**************************************************************
    Stack()
    {
        head = NULL;
    }
    //***********************************************************
    // Member function push pushes the argument onto the stack. *
    //***********************************************************
    void push(string x)
    {
        Node *newNode = new Node;
        newNode->value = x;
        
        if(isEmpty())
        {
            head = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    //****************************************************
    // Member function pop pops the value at the top     *
    // of the stack off, and returns it.                 *
    //****************************************************
    string pop()
    {
        Node *temp = NULL;
        string result;
        if(!isEmpty())
        {
            result = head->value;
            temp = head->next;
            delete head;
            head = temp;
        }
        return result;
    }
    //****************************************************
    // Member function isEmpty returns true if the stack *
    // is empty, or false otherwise.                     *  
    //****************************************************
    bool isEmpty()
    {
        return (head == NULL);
    }
};

#endif /* Stack_h */
