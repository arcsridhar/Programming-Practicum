//
//  main.cpp
//  Exercise3
//
//  Archana Sridhar
//   a_s1316
//
// Assignment Number: 1
// CS 5301.251 Spring 2019
// Instructor: Jill Seaman
//
//  C++ program that inputs the number of grams of carbohydrate,fat, and protein,then outputs the total calories, and percentage of calories from each macro-nutrient

#include <iostream>
#include <iomanip>
const int carb_cal=4;
const int fat_cal=9;
const int protein_cal=4;
int main() {
    int carb,fat,protein,total_calories;
    std::cout << "Please enter the grams of carbohydrate: ";
    std::cin >> carb;
    std::cout << "Please enter the grams of fat: ";
    std::cin >> fat;
    std::cout << "Please enter the grams of protein: ";
    std::cin >> protein;
    
    //Calculating the calories of carbohydrates,protein,fat and total calories
    double c1=carb_cal*carb;
    double c2=fat_cal*fat;
    double c3=protein_cal*protein;
    total_calories=c1+c2+c3;
    
    //Displaying the total calories
    std::cout << "Total calories: " << total_calories;
    
    //Calculating the percentage of calories
    double carb_percent=(c1/total_calories)*100;
    double fat_percent=(c2/total_calories)*100;
    double protein_percent=(c3/total_calories)*100;
    std::cout << "\n% of calories from carbs: " << std::setprecision(3) << carb_percent;
    std::cout << "\n% of calories from fat: " << std::setprecision(3) << fat_percent;
    std::cout << "\n% of calories from protein: " << std::setprecision(3) << protein_percent;
}
