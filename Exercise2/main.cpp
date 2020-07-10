//
//  main.cpp
//  Exercise2
//
//  Archana Sridhar
//  a_s1316
//
// Assignment Number: 1
// CS 5301.251 Spring 2019
// Instructor: Jill Seaman
//
// C++ program that prompts the user to input a distance in total feet then outputs the distance in miles, yards, and feet

#include <iostream>

int main() {
    int feet,yards=0,miles=0;
    
    //Enter the total distance in feet
    std::cout << "Please enter the total distance in feet :";
    std::cin >> feet;
    
 
    if(feet>3)
    {
        yards=feet/3;
        feet=feet%3;
    }
    if(yards>=1760)
    {
        miles=yards/1760;
        yards=yards%1760;
    }
    //Printing the desired output in milles,yards and feet
    std::cout<<"The distance is :"<< miles <<" miles," << yards <<" yards, " << feet << " feet";
   
}

