#pragma once
#include <iostream>
#include<algorithm>
#include<tuple>
using namespace std;
class Fraction
{
private:
	int top, bottom;
public:
    //Constructors
    Fraction(int top, int bottom);
    Fraction(const Fraction& obj);
    //operators
    Fraction& operator=(const Fraction& obj); //Assigns an obj to another obj
    Fraction operator+(const Fraction& obj); //sums two fractions
    Fraction operator-(const Fraction& obj); //substracts
    Fraction operator*(const Fraction& obj); //multiply
    Fraction operator/(const Fraction& obj); // divide
    //methods
    int gcd(int a, int b); //returns greatest common divisor of two numbers
    int getNumerator(); //returns numerator
    int getDenominator(); // returns denominator
    double getValue(); //gets decimal value of fraction
    tuple<int, int> simplifyFraction(int numerator, int denominator); //returns a simplified version of fraction eg. 3/6=1/2
    //friends
    friend istream& operator>>(istream& in, Fraction &input); //cin overloading
    friend ostream& operator<<(ostream& in, Fraction output); //cout overloading
    

};
