#include <iostream>
using namespace std;


int main()
{
	double firstNum;
	double secondNum;
	char Operator;
	
	cout << "WELCOME TO BASIC CALCULATOR!!!" << endl;


	cout << "Enter First Number" << endl;
	cin >> firstNum;

	cout << "Enter what you would like to do (+,-,*,/): " << endl;
	cin >> Operator;

	cout << "Enter Second Number" << endl;
	cin >> secondNum;

	switch (Operator) {
	case '+': 
		cout << firstNum << " + " << secondNum << " = " << firstNum + secondNum;
		break;
	case '-':
		cout << firstNum << " - " << secondNum << " = " << firstNum - secondNum;
		break;
	case '*':
		cout << firstNum << " * " << secondNum << " = " << firstNum * secondNum;
		break;
	case '/':
		if (secondNum == 0) {
			cout << "Undefined, cannot divide by 0" << endl;
			break;
		}
		else {
			cout << firstNum << " / " << secondNum << " = " << firstNum / secondNum;
			break;
		}
	default:
		cout << "invalid operation" << endl;
		break;
	}
}
