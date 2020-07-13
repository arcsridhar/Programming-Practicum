// File Name: Driver.cpp
//
// Author: Archana Sridhar
// Date: 4/22/2019
// Assignment Number: 6
// CS 5301 Spring 2019
// Instructor: Dr.Jill Seaman
//
// A demo driver that uses the Queue to simulate the management of the line of people
// waiting to ride a roller coaster in an amusement park.

#include "Queue.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void outputTrain(Queue &q,int &tcount,int &rcount)
{
    tcount++;
    cout << endl << "Train #" << tcount << endl;
    cout << "----------" << endl;
    while(!q.isEmpty())
    {
        cout << q.dequeue() << endl;
        rcount++;
    }
}

int main()
{
    int limit;
    string name;
    Queue q;
    int size;
    int riderCount = 0;
    int trainCount = 0;
    
    
    ifstream inputFile;
    inputFile.open("/Users/Archana/Documents/C++/Projects/assign6_a_s1316/assign6_a_s1316/riders.txt");
    inputFile >> limit;
    while (inputFile >> name >> size)
    {
        if(size > limit-q.size())
        {
            outputTrain(q, trainCount, riderCount);
        }
        for(int i = 0; i < size; i++)
        {
            q.enqueue(name+" "+to_string(i+1));
        }
    }
    if(!q.isEmpty())
    {
        outputTrain(q, trainCount, riderCount);
    }
    cout << endl;
    cout << "Total Riders : " << riderCount << endl;
    cout << "Total Trains : " << trainCount << endl;
}
