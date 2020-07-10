//
//  main.cpp
//  Lab 3 Exercise 2
//
//  Archana Sridhar
//  a_s1316
//  Date : 02/10/2019
// Lab Assignment Number: 3
// CS 5301.251 Spring 2019
// Instructor: Dr.Jill Seaman
//
//   C++ program that allows the user to enter a sequence of ratings for a product sold on Amazon and perform operations

#include <iostream>
#include <iomanip>
using namespace std;

void inputRatings(int [],int &);
double average(int [],int );
void calcDistribution(int [],int ,int []);
void printResults(int [],int );
int main()
{
    cout << fixed << setprecision(1);
    int ratings[1000],count=1;
    int distribution[5]={0};
    inputRatings(ratings,count);
    cout <<"This item received " << count-1 <<" ratings"<<endl;
    cout << "The average ratings was "<< average(ratings,count) << " stars"<<endl;
    calcDistribution(ratings, count, distribution);
    printResults(distribution,count);
    return 0;
}
void inputRatings(int ratings[],int &x)
{
    int num,count=1;
    cout << "Please input the ratings for the product (between 1 and 5)" <<endl;
    cout << "followed by a -1" << endl;
    cin>>num;
    while(num!=-1)
    {
        count++;
        ratings[count-1]=num;
        cin >> num;
    }
    x=count;
}
double average(int ratings[],int x)
{
    double sum=0.0;
    for (int i=0 ;i < x; i++)
    {
        if(ratings[i]>0 && ratings[i]<6)
        {
            sum+=ratings[i];
        }
    }
    double avg= sum/(x-1);
    return avg;
}
void calcDistribution(int ratings[] ,int x, int distribution[])
{
    for (int i=0 ; i < x ; i++)
    {
        if (ratings[i] == 1)
        {
            distribution[4]++;
        }
        else if (ratings[i] == 2)
        {
            distribution[3]++;
        }
        else if (ratings[i] == 3)
        {
            distribution[2]++;
        }
        else if (ratings[i] == 4)
        {
            distribution[1]++;
        }
        else if (ratings[i] == 5)
        {
            distribution[0]++;
        }
    }
}
void printResults(int distribution[],int x)
{
    for(int i=0 ; i < 5; i++)
    {
        int percentage=distribution[i]*100/(x-1);
        cout << i+1 << "..."<< percentage <<"%"<<endl;
    }
}
