// Lab 2 exercise 2
// Spring 2019
// Jill Seaman
// js236

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(1) << endl;
    
    int steps;
    int total = 0;
    int max;
    int days = 0;
    int count = 0;
    
    cout << "Please enter the list of steps walked per day, "
         << "(enter -1 when finished): " << endl;
    
    cin >> steps;
    max = steps;
    
    while (steps != -1) {
        total = total + steps;
        days++;
        if (steps < 5000)
            count++;
        if (steps > max)
            max = steps;
        cin >> steps;
    }
    
    if (days > 0) {     // avoid divide by 0 (not required)
        cout << "Average steps per day = " << static_cast<double>(total)/days
             << endl;
        cout << "Days < 5000 = " << count << endl;
        cout << "Max steps   = " << max << endl;
    }
    
}




