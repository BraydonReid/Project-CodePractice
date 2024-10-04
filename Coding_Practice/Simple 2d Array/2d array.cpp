#include<iostream>
using namespace std;


void printArrayAsk() {
	int b[100][100];
	int r, c;

	cout << "enter number of rows: " << endl;
	cin >> r;

	cout << "enter number of columns: " << endl;

	cin >> c;


	cout << "Enter your Variables, Max number is:  " << r * c << endl;
	/// for loop runs throught the 2d array inputing the values
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> b[i][j];
		}
	}


	/// displays the 2d array in row format
	cout << "Row format: " << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;

	}


	cout << "Column format: " << endl;

	// displays the 2d array in column format
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			cout << b[j][i] << " ";
		}
		cout << endl;
	}
}
// Value of columns is mandatory while rows are not
void PrintArray(int a[][5], int c, int r) {

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;

	}
}
int main() {
	//2d array will be filled with 0s if element is empty
	int a[5][5] = {
	{1,2},
	{3,4}
	};

	printArrayAsk();
	//displays how the 2d array will be filled with 0s if element is empty
	cout << "Array that was only assigned 4 values with the capacity for 25:" << endl;
	PrintArray(a, 5, 5);


	return 0;

}