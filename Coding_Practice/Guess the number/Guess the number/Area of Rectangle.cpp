// Area of Rectangle
#include <iostream>
using namespace std;



    void printRectangle(int length, int width) {
     

        cout << "Rectangle length = " << length << ". width = " << width << endl;
        cout << "Area: " << length * width << endl;

        for (int j = 0; j < length; j++) {
            cout << '-';
        }
        cout << endl;



        for (int i = 0; i < width; i++) {
            cout << '|';
            for (int k = 0; k < length - 2; k++) {
                cout << ' ';
            }
            cout << '|';
            cout << endl;
        }
        

        for (int j = 0; j < length; j++) {
            cout << '-';
        }
        cout << endl;
    }


int main(){
    int length;
    int width;


    cout << "Please Enter the Length of the Rectangle: " << endl;
    cin >> length;

    cout << "Please Enter the Width of the Rectangle: " << endl;
    cin >> width;
    
    printRectangle(length, width);

}
