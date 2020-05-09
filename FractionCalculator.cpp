#include "FractionCalculator.h"
#include "Fraction.h"
#include <iostream>
using namespace std;
//method
Fraction FractionCalculator::calculateFractions(Fraction obj, Fraction obj1) {
	
	char operatorChoice;
	cout << "Choose the operation eg.'+', '-', etc: "<<endl;
	cin >> operatorChoice;
	Fraction newFract(1, 1);
	switch (operatorChoice) {
	case '+':
		newFract = obj1 + obj;
		cout << "Result: "<< newFract << endl;
		return newFract;
		break;
	case '-':
		newFract = obj1 - obj;
		cout << "Result: " << newFract << endl;
		return newFract;
		break;
	case '*':
		newFract = obj1 * obj;
		cout << "Result: " << newFract << endl;
		return newFract;
		break;
	case '/':
		newFract = obj1 / obj;
		cout << "Result: " << newFract << endl;
		return newFract;
		break;
	default:
		cout << "Invalid input"<<endl;

		
	}
	return obj;
}