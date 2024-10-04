// Fractions

#include <iostream>
#include "FractionUse.cpp"
using namespace std;

int main()
{
	//variables made used fraction class
	fraction f1(10, 2);
	fraction f2(15, 4);
	fraction f3 = f2 + f1;
	fraction f4 = f1 * f2;

	cout << "before adding together: " << endl;

	cout << "f1: ";
	f1.print();
	cout << "f2: ";
	f2.print();

	cout << "Adds f2 + f1 to make f3: ";
	f3.print();

	cout << "multiples f1 and f2 to make f4: ";
	f4.print();


	cout << "is f3 equal to f4?" << endl;
	if (f3 == f4) {
		cout << "equal" << endl;
	}
	else {
		cout << "not equal" << endl;
	}
	
	//adds two fractions together in non standard method
	f1 = f1.add(f2);
	cout << "f1 += f2: " << endl;

	cout << "f1: ";
	f1.print();

	cout << "After multiplying new f1 by f2: " << endl;
	//multiplies two fractions together in non standard method
	f1.multiply(f2);
	f1.print();
	 
	

	return 0;

}
