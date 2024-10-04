#include <iostream>

using namespace std;

void ReverseIt(char* o, char* r) {
    int size = 0;
    int space = 0;
    char* copy = o;
    char* copy2 = o;
    while (*copy2 != '\0') {
        copy2++;
        size++;
    }

    for(int i = size; i >= 0; i--) {
        if (*copy2-- == ' ') {
            space = i;
            break;
        }
    }
    *copy2++;
    for (int i = space; i < size -1; i++) {
        *r = *copy2;
        *r++;
        *copy2++;
    }


    *r++;
    *r = ',';
    *r++;
    *r = ' ';

    while (o != r) {
        *r = *o;
    }

}

    int main()
    {
        char original[] = "Conan The Barbarian\0";
        char reversed[100];

       ReverseIt(original, reversed);

        cout << original << " reversed is " << reversed << endl;
    }