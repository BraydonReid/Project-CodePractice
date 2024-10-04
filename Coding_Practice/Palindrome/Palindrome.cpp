//Palindrome

#include <iostream>
using namespace std;


bool isPalindrome(int x) {
	//creates palindrom variable and original variable to compare with
	long palin = 0;
	long orig = x;

	// assigns x variable to palin variable with digits reversed
	while (x > 0) {
		palin = (palin * 10) + (x % 10);
		x = x / 10;
	}

	// checks to see if they equal the same thing (if yes then return true, otherwise returns false)
	if (orig == palin) {
		return true;
	}
	return false;
}


int main() {

	int number;

	cout << "Please enter number to check if it is Palindrome: " << endl;

	cin >> number;


	if (isPalindrome(number)) {
		cout << number << " is palindrome!" << endl;
	}
	else {
		cout << number << " is not palindrome!" << endl;
	}


	return 0;
}

