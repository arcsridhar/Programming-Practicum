//
//  main.cpp
//  Lab 2 Exercise 2
//
//  Archana Sridhar
//  a_s1316
//  Date : 02/04/2019
// Lab Assignment Number: 2
// CS 5301.251 Spring 2019
// Instructor: Dr.Jill Seaman
//
//  C++ program  that asks the user to enter a list of the steps walked each day that output the desired Average, number of days less than 5000 steps and maximum of steps with proper labels

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int steps,count=0,maximum=0,days=0;
    double avg_steps,total=0;
    
    cout << "Please enter the list of steps walked per day,(enter -1 when finished): " <<endl;
    cin >> steps;
    while (steps != -1 && steps > 0)
    {
        if(steps > maximum)
        {
            maximum=steps;
        }
        if(steps < 5000)
        {
            days++;
        }
        total=total+steps;
        count=count+1;
        cin >> steps;
    }
    if(count != 0)
    {
        avg_steps=total/count;
        cout << fixed << setprecision(1);
        cout << "\nAverage steps per day = " << avg_steps;
        cout << "\nDays < 5000 = " << days;
        cout << "\nMax steps = " << maximum;
    }
}
