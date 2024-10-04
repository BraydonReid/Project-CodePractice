#include <iostream>
#include<vector>
using namespace std;


int singleNumber(int* nums, const int size) {
	/// finds one element to compare the rest of the vector too
	for (int i = 0; i < size; i++) {
		/// resets count for every element selection
		int count = 0;
		/// compares the selected element to the rest to the vector
		for (int j = 0; j < size; j++) {
			/// if found it updates count
			if (nums[i] == nums[j]) {
				count++;
			}
		}
		/// if count == 1 it means the element was only found once
		if (count == 1) {
			return nums[i];
		}
	}

	return -1;
}

void printArr(int* arr, const int size) {
	cout << "The array: ";

	for (int i = 0; i < size; i++) {
		if (i == 0) {
			cout << "[" << arr[i] << ",";
		}
		else if (i == size - 1) {
			cout << arr[i] << "]";
		}
		else {
			cout << arr[i] << ",";
		}
	}
	cout << endl;
}

int main() {
	const int size = 9;
	int num[size] = { 1, 1, 2, 2, 3, 4, 4, 5, 5 };
	int single;

	single = singleNumber(num, size);

	printArr(num, size);

	cout << "The number " << single << " only occurs once in the array!" << endl;

}