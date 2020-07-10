//
//  main.cpp
//  Lab 3 Exercise 1
//
//  Archana Sridhar
//  a_s1316
//  Date : 02/10/2019
// Lab Assignment Number: 3
// CS 5301.251 Spring 2019
// Instructor: Dr.Jill Seaman
//
//  C++ program that ask the user to input the center and a point on the circle and then output the circle’s radius, diameter, circumference, and area.

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void input2points(double &,double &,double &,double &);
double distance(double ,double ,double ,double );
double circumference(double);
double area(double);
int main()
{
    double r;
    double x1,y1,x2,y2;
    input2points(x1,y1,x2,y2);
    r=distance(x1,y1,x2,y2);
    circumference(r);
    cout << "The area of the circle =" << area(r)<<endl;
}

void input2points(double &x1,double &y1,double &x2,double &y2)
{
    cout << "Enter the center of the circle (x and y coordinates):";
    cin >> x1 >> y1;
    cout << "Enter a point on the circle (x and y coordinates):";
    cin >> x2 >> y2;
}
double distance(double x1,double y1,double x2,double y2)
{
    double x = (x1 - x2);
    double y = (y1 - y2);
    
    double dist = pow(x,2)+pow(y,2);
    double total_distance=sqrt(dist);
    return total_distance;
}
double circumference(double radius)
{
    double diameter= 2 * (radius);
    cout << fixed << setprecision(2);
    cout << "The diameter of the circle =" <<diameter << endl;
    double circle_circumference=M_PI*diameter;
    cout << "The circumference of the circle =" << circle_circumference << endl;
    return circle_circumference;
}
double area(double radius)
{
    double circle_area=M_PI*radius*radius;
    return circle_area;
}

