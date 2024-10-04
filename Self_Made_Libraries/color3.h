'
'#include<iostream>
#include"windows.h"


using namespace std;


void printColor(int num, int colorValue) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// you can loop k higher to see more color choices
	
		// pick the colorattribute k you want
		SetConsoleTextAttribute(hConsole, colorValue);
		cout << num << endl;
		SetConsoleTextAttribute(hConsole, 0x07);
	
}


void printColor(string str, int colorValue) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// you can loop k higher to see more color choices

		// pick the colorattribute k you want
	SetConsoleTextAttribute(hConsole, colorValue);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, 0x07);
	


}







