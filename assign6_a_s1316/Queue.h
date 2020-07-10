// File Name: Queue.h
//
// Author: Archana Sridhar
// Date: 4/22/2019
// Assignment Number: 6
// CS 5301 Spring 2019
// Instructor: Dr.Jill Seaman
//
//  A linked list of string to implement the queue operations. 
//

#ifndef Queue_h
#define Queue_h
#include <string>
#include <iostream>
#define SIZE 10
using namespace std;
class Queue
{
    private:
    struct Node
    {
        string value;
        Node *next;
    };
    Node *front;
    Node *rear;
    int numItems;

    public:
    //**************************************************************
    // This constructor creates an empty queue of a specified size.
    //**************************************************************
    Queue()
    {
        front = rear = NULL;
        numItems = 0;
        numItems = 0;
    }
    //**************************************************************
    // Function enqueue inserts a value at the rear of the queue. 
    //**************************************************************
    void enqueue(string x)
    {
        Node *newNode = new Node;
        newNode->value = x;
        newNode->next = NULL;

        if(isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        numItems++;
    }
    //******************************************************
    // Dequeue removes the value at the front of the       *
    // queue and returns the value.                        *
    //******************************************************
    string dequeue()
    {
        Node *temp = NULL;
        string result;
        if(!isEmpty())
        {
            result = front->value;

            //Remove the front node and delete it
            temp = front;
            front = front->next;
            delete temp;
            
            numItems--;
        }
        return result;
    }
    //******************************************************
    // isEmpty returns true if the queue is empty,         *
    // otherwise false.                                    *
    //******************************************************
    bool isEmpty()
    {
        return (front == NULL);
    }
    //******************************************************
    //returns the number of elements in the queue          *
    //******************************************************
    int size()
    {
        return numItems;
    }
};

#endif /* Queue_h */
