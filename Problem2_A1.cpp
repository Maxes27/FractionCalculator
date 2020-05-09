// Problem2_A1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "FractionCalculator.h"
#include "Fraction.h"
#include <iostream>
#include <algorithm>
using namespace std;
Fraction fractionInput() {
    Fraction myFract(1, 1);
    cout << "Enter a fraction\n";
    cin >> myFract;
    cout << "you entered " << myFract << endl;
    return myFract;
} //allows user to input a fraction
Fraction calculateMethod(Fraction obj) {
        Fraction obj1 = fractionInput();
        FractionCalculator calculatorObj;
        obj1 = calculatorObj.calculateFractions(obj, obj1);
        return obj1;
    } //allows user to perform calculations on fractions
int main()
{
    try {
        Fraction obj = fractionInput();
        while (true) {
            cout << "Do you want to do a calculation on that fraction? type 1 for yes and 2 for no" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
            case 1:
                obj  = calculateMethod(obj);
                break;
            case 2:
                exit(0);
                break;
            default:
                cout << "Invalid input" << endl;
            }
            
        }
        
        
    }
    catch (int e) {
        if (e == 1) {
            cout << "Unaccepted character entered." << endl;
        }
        else {
            cout << "There was an invalid input, maybe you entered zero as denominator." << endl;
        }
    }
}

