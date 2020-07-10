// Lab 2 exercise 1
// Spring 2019
// Jill Seaman
// js236

#include <iostream>
#include <iomanip>
using namespace std;
	
int main()
{
    int carbs, fat, protein;
    int totalCalories;
    double percentCarb, percentFat, percentProtein;
    
    cout << "Please enter the grams of carbohydrate: ";
    cin >> carbs;
    
    cout << "Please enter the grams of fat: ";
    cin >> fat;
    
    cout << "Please enter the grams of protein: ";
    cin >> protein;
    
    if (carbs>=0 && fat>=0 && protein>=0 && carbs+fat+protein>0) {
        totalCalories = carbs*4 + fat*9 + protein*4;
        percentCarb = carbs*4.0 / totalCalories * 100;
        percentFat = fat*9.0 / totalCalories * 100;
        
        cout << fixed << setprecision(1);
        
        cout << "Total calories: " << totalCalories << endl;
        if (percentFat < 30)
            cout << "This food is low in fat." << endl;
        else if (carbs < 5 || percentCarb <= 8)
            cout << "This food is keto approved." << endl;
        else
            cout << "This food is neither low fat nor keto approved." << endl;
    } else {
        cout << "The carbs, fat, and protein must not be negative" << endl;
        cout << "and the carbs, fat, and protein cannot all be zero." << endl;
    }
    
    return 0;
}

