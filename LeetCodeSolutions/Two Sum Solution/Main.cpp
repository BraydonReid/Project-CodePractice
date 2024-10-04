#include <iostream>
#include<vector>
using namespace std;

// function searches through the array and finds the value that only occurs once.
int* singleNumber(int* nums) {
	// finds one element to compare the rest of the vector too
	for (int i = 0; i < nums.size(); i++) {
		// resets count for every element selection
		int count = 0;
		// compares the selected element to the rest to the vector
		for (int j = 0; j < nums.size(); j++) {
			// if found it updates count
			if (nums[i] == nums[j]) {
				count++;
			}
		}
		// if count == 1 it means the element was only found once
		if (count == 1) {
			return nums[i];
		}
	}

	return -1;
}


int main() {


	int num[] = {1, 1, 2, 2, 3, 4, 4};
	int single;

	single = singleNumber(num);

	cout <<"The number " << single << " only occurs once in the array!" << endl;

}