//
//  main.cpp
//  Exercise1
//
//  Archana Sridhar
//  a_s1316
//
// Assignment Number: 1
// CS 5301.251 Spring 2019
// Instructor: Jill Seaman
//
// C++ program to convert miles per gallon (MPGus) to liters per 100km 

#include <iostream>
#include <iomanip>
using namespace std;

const double c1=3.785411784;
const double c2=1.609344;
const int value=100;

int main() {
    double MPG_US;
    double liters;
    
    //Getting the value of miles per gallon
    cout <<"Please enter the MPG amount : ";
    cin >> MPG_US;
    liters=(value*c1)/(c2*MPG_US);
    
    //Displaying the value in liters per 100 km
    cout << "Liters per 100 km is : " << std::setprecision(3) << liters;
}
