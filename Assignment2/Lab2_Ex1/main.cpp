//
//  main.cpp
//  Lab 2 Exercise 1
//
//  Archana Sridhar
//  a_s1316
//  Date : 02/04/2019
// Lab Assignment Number: 2
// CS 5301.251 Spring 2019
// Instructor: Dr.Jill Seaman
//
//   C++ program that asks the user for the number of grams of carbohydrate, fat and protein in a given food which determines if the food can be considered low fat or if it is useful for a Ketogenic diet

#include <iostream>
#include <iomanip>
using namespace std;

const int carb_cal=4;
const int fat_cal=9;
const int protein_cal=4;

int main() {
    int carb,fat,protein,total_calories,total_grams;
    cout << "Please enter the grams of carbohydrate: ";
    cin >> carb;
    cout << "Please enter the grams of fat: ";
    cin >> fat;
    cout << "Please enter the grams of protein: ";
    cin >> protein;
    
    total_grams= carb+fat+protein;
    if (carb > 0 && fat > 0 && protein > 0 && total_grams != 0)
    {
        double c1=carb_cal*carb;
        double c2=fat_cal*fat;
        double c3=protein_cal*protein;
        total_calories=c1+c2+c3;
        
        cout <<"Total calories:" <<total_calories <<endl;
        if (c2 < (0.3*total_calories))
        {
            cout <<"This food is low in fat."<<endl;
        }
        else if( carb < 5 || c1 <= (0.08*total_calories))
        {
            cout <<"This food is keto approved."<<endl;
        }
        else
        {
            cout <<"This food is neither low fat nor keto approved."<<endl;
        }
        
    }
    else
    {
        cout << "The carbs, fat, and protein must not be negative" << endl;
        cout << "and the carbs, fat, and protein cannot all be zero";
    }
}
