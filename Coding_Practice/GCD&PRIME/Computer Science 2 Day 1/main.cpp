//GCD&PRIME
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// returns true if prime and false otherwise.
bool isPrime(int num) {
	// This will cause any num value less than 2 to return false
	if (num < 2) {
		return false;
	}
	// This will cause the value to be false if num is equal to two
	if (num == 2) {
		return true;
	}
	// This will cause any num value % 2 to return false if it equals 0
	if (num % 2 == 0) {
		return false;
	}
	//Loop will until the factor times itself is greater than the input number, and increments by 2 to keep the factor value odd.
	for (int factor = 3; factor* factor <= num; factor += 2) {
		//if num % and odd number equals 0 it will return false
		if (num % factor == 0) {
			return false;
		}
	}
	// if none above are true then the return value will be true.
	return true;
}

int countBalancePrime(int upto) {
	int count = 0;
	for (int i = 3; i < upto; i++) {
		int prev = i - 2;
		int next = i + 2;
		if (isPrime(i) && isPrime(prev) && isPrime(next)) {
			if ((prev + next) / 2 == i) {
				count++;
			}
		}
	}
	return count;
}

bool isTruncated(int num) {
	while (isPrime(num) != 0) {
		num = num / 10;
	}
	return num == 0;
}


int gcd(int a, int  b) {
	int result = min(a, b);
	while (result > 0) {
		if (a % result == 0 && b % result == 0) {
			break;
		}
		result--;
	}
	return result;
}


int main() {
	int prime;
	int low;
	int high;
	vector<int> primeNum;

	cout << "Enter the lowest number you want to check: ";
	cin >> low;

	cout << "Enter the highest number you want to check: ";
	cin >> high;

	for (int i = low; i <= high; i++) {
		if (isPrime(i)) {
			cout << i << " is prime!" << endl;
			primeNum.push_back(i);

		}
		else {
			cout << i << " is not prime!" << endl;
		}
	}

	cout << "Count Balanced Prime: ";
	prime = countBalancePrime(100);
	cout << prime << endl;

	int x, y;
	cout << "FINDING GCD BETWEEN TWO NUMBERS" << endl;

	cout << "Please enter the first integer: ";
	cin >> x;
	cout << "Please enter the second integer you would like to compare with the first integer: ";
	cin >> y;

	int GCD = gcd(x, y);

	cout << "The Greatest Common Divisor for " << x << " and " << y << " is: " << GCD << endl;

	if (isPrime(GCD)) {
		cout << GCD << " is prime!" << endl;
	}
	else {
		cout << GCD << " is not prime!" << endl;
	}
	
	return 0;
}