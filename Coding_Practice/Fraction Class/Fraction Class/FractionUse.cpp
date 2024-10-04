#include <iostream>
#include <cmath>
using namespace std;

class fraction {

	//creates variables for numerator and denominator of fraction
	int numerator;
	int denominator;

public:
	//creates a way of inputing a fraction into a class
	fraction(int numerators, int  denominators) {
		numerator = numerators;
		denominator = denominators;

		
	}
	//prints the fraction that is inputed.
	void print() {
		cout << numerator << "/" << denominator << endl;
	}

	//functions adds to fractions together
	fraction add(fraction const& f2) {
		int lcm = denominator * f2.denominator;
		int x = lcm / denominator;
		int y = lcm / f2.denominator;
		int num = x * numerator + y * f2.numerator;

		
		fraction fnew(num, lcm);



		fnew.simplify();
		return fnew;

	}


	//uses operator overloading to use a more traditional '+' to add fractions
		fraction operator+(fraction const& f2) {
		int lcm = denominator * f2.denominator;
		int x = lcm / denominator;
		int y = lcm / f2.denominator;
		int num = x * numerator + y * f2.numerator;


		fraction fnew(num, lcm);



		fnew.simplify();
		return fnew;
	}

	// multiplies two fractions together in a non standard approach
	void multiply(fraction const& f2) {
		numerator = numerator * f2.numerator;
		denominator = denominator * f2.denominator;
		simplify();
	}

	// multiplies two fractions together in a standard approach using '*'
	fraction operator*(fraction const& f2) {
		int n = numerator * f2.numerator;
		int d = denominator * f2.denominator;
		

		fraction fnew(n, d);
		fnew.simplify();


		return fnew;
	}

	// determines rather or not two fractions are equal
	bool operator==(fraction const& f2) {
		return (numerator == f2.numerator && denominator == f2.denominator);

	}

	
	// simplifies fractions
	void simplify() {
		int gcd = 1;
		int j = min(numerator, denominator);
 

		// finds gcd of the fraction manually
		for (int i = 1; i <= j; i++) {
			if (numerator % i == 0 && denominator % i == 0) {
				gcd = i;
			}
		}
		// simplifies
		numerator = numerator / gcd;
		denominator = denominator / gcd;

	}


};