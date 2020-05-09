#include "Fraction.h"
//constructors
Fraction::Fraction(int top = 1, int bottom = 1) :top(top), bottom(bottom) {}
Fraction::Fraction(const Fraction& obj) : top(obj.top), bottom(obj.bottom) {}

//methods
int Fraction::gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int Fraction::getNumerator() { return top; }
int Fraction::getDenominator() { return bottom; }
double Fraction::getValue() { return double(top) / bottom; }
tuple<int, int> Fraction::simplifyFraction(int numerator, int denominator) {
    int commonRatio = gcd(numerator, denominator);
    return make_tuple(numerator / commonRatio, denominator / commonRatio);
}

//operators
istream& operator>>(istream& in, Fraction &input) {
    int numer;
    int denom = 1;
    int whole = 0;
    int peekchar;
    bool valid = false;

    in >> numer; //get the numerator
    peekchar = in.peek(); //peek at next character
    /*if(in && peekchar == '+') { //if next character is a +
        in.get(); //skip the + character
        whole = numer; //then first character was whole, not numerator
        in >> numer; //get the real numerator
        valid = true;
        peekchar = in.peek();
    }*/
    if (in && peekchar == '/') { //if next character is a /
        in.get(); //skip the / character
        in.clear();
        in >> denom; //get the denominator
        peekchar = in.peek();
        valid = true;
    }
    else {
        throw 1;
    }
    if (in && peekchar==10) { //if we succeeded in reading
        if (denom == 0)
        {
            throw 2;
        }

        numer += (whole * denom);
        tie(numer, denom) = input.simplifyFraction(numer, denom);
        input = Fraction(numer, denom);
    }
    else {
        throw 1;
    }
    return in;
}
ostream& operator<<(ostream& in, Fraction output){
    return in << output.getNumerator() << '/' << output.getDenominator();
}
Fraction Fraction::operator+(const Fraction& obj) {
    Fraction newObj(1, 1);
    newObj.top = top*obj.bottom + obj.top*bottom;
    newObj.bottom = bottom * obj.bottom;
    tie(newObj.top, newObj.bottom) = simplifyFraction(newObj.top, newObj.bottom);
    return newObj;
}
Fraction Fraction::operator-(const Fraction& obj) {
    Fraction newObj(1, 1);
    newObj.top = top * obj.bottom - obj.top * bottom;
    newObj.bottom = bottom * obj.bottom;
    tie(newObj.top, newObj.bottom) = simplifyFraction(newObj.top, newObj.bottom);
    return newObj;
}
Fraction Fraction::operator*(const Fraction& obj) {
    Fraction newObj(1, 1);
    newObj.top = top * obj.top;
    newObj.bottom = bottom * obj.bottom;
    tie(newObj.top, newObj.bottom) = simplifyFraction(newObj.top, newObj.bottom);
    return newObj;
}
Fraction Fraction::operator/(const Fraction& obj) {
    Fraction newObj(1, 1);
    newObj.top = top * obj.bottom;
    newObj.bottom = bottom * obj.top;
    tie(newObj.top, newObj.bottom) = simplifyFraction(newObj.top, newObj.bottom);
    return newObj;
}
Fraction& Fraction::operator=(const Fraction& obj) { top = obj.top; bottom = obj.bottom; return *this; }


