#include <iostream>
#include <algorithm>
#include<random>
#include <vector>
#include<chrono>
//#include<bits/stdc++.h> //Master HeaderFile
using namespace std;

/// creates a random integer
int randIntGenerator(int low, int high) {
	random_device rd;  // Obtain a random number from hardware
	mt19937 eng(rd()); // Seed the generator
	uniform_int_distribution<> distribution(low, high); // Define the range
	return distribution(eng); // Generate the random number
}

// Tracks time
double getTimeInSeconds() {
	auto now = std::chrono::high_resolution_clock::now();
	auto duration = now.time_since_epoch();
	auto seconds = std::chrono::duration_cast<std::chrono::duration<double>>(duration).count();
	return seconds;
}

/// assigns random integers to an array
int* randArr(int size, int low, int high) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = randIntGenerator(low, high);
	return arr;
}

vector<int> randVec(int size, int low, int high) {
	vector<int> vec;
	for (int i = 0; i < size; i++)
		vec.push_back(randIntGenerator(low, high));
	return vec;
}


					/*Start of Merge Sort*/     //Time Complexity: nlog(n)  
////////////////////////////////////////////////////////////

void merge(int array[], int const left, int const mid,
	int const right)
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

					/*End of Merge Sort*/
////////////////////////////////////////////////////////////


void selectionSort(int arr[], int size) {
	for (int i = 0; i < size-2; i++) {
		int smallest = i;
		for (int j = i + 1; j <= size - 1; j++) {
			if (arr[j] < arr[smallest]) {
				smallest = j;
			}
		}

		if (arr[i] > smallest) {
			swap(arr[i], arr[smallest]);
		}
	}
}

void bubbleSort(int arr[], int size) {
	for (int count = 1; count <= size - 1; count++) {
		int flag = 0;
		for (int j = 0; j <= size - 2; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) {	/// checks if array is already sorted
			break;
		}
	}
	
}

void InsertionSort(int* arr, int size) {
	int curr;
	int start;
	for (int i = 1; i < size; i++) {
		curr = arr[i];
		int j = i - 1;
		while (curr < arr[j] && arr[j] > curr) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = curr;
	}
}


int partition(vector<int>& v, int start, int end) {
	int pivot = v[end];
	int mid = start;

	for (int i = start; i < end; i++) {
		if (v[i] < pivot) {
			if (mid != i) {
				swap(v[i], v[mid]);
			}
			mid++;
		}
	}
	v[end] = v[mid];
	v[mid] = pivot;
	return mid;
}



void quickSort(vector<int>& v, int start, int end) {
	if (start >= end) return;

	int mid = partition(v, start, end);
	quickSort(v, start, mid - 1);
	quickSort(v, mid + 1, end);
}




					/*Start of Radix Sort*/			//Time complexity: digits * (#elements + b)   b = base of number system being used
////////////////////////////////////////////////////////////

/// finds the max number of the array
int findMaxNum(int* arr, int size) {
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

// Function to perform counting sort based on digit
void countingSort(int arr[], int size, int e) {
	int* output = new int[size];
	int count[10] = { 0 };
	
	/// gets the value of the current digit
	for (int i = 0; i < size; i++) count[(arr[i] / e) % 10]++;
	
	/// counts the digits less than or equal to itself
	for (int i = 1; i < 10; i++) count[i] += count[i - 1];

	/// places elements into the output array in correct position
	for (int i = size - 1; i >= 0; i--) {
		output[count[(arr[i] / e) % 10] - 1] = arr[i];
		count[(arr[i] / e) % 10]--;
	}

	/// places the elements back into the original array in correct position
	for (int i = 0; i < size; i++)	arr[i] = output[i];

	/// releases the memory
	delete[] output; 
}

void radixSort(int* arr, int size) {

	///finds the maximum value in the array
	int max = findMaxNum(arr, size);

	/// e stand for exponent
	/// loops over every digit place of the numbers stored in the array
	for (int e = 1; max / e > 0; e *= 10) {
		countingSort(arr, size, e);
	}
}
					/*End of Radix Sort*/
////////////////////////////////////////////////////////////

                                             /*Serching*/
///////////////////////////////////////////////////////////////////////////////////////////////////


int binarySearch(int arr[], int size, int key) {
	int low = 0;
	int high = size - 1;

	while (low <= high) {
		int middle = low + (high - low) / 2; // Calculate the middle index correctly

		if (key == arr[middle]) {
			return middle;
		}
		else if (key > arr[middle]) {
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
	}

	return -1;
}


int LinearSearch(int arr[], int size, int key) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			return i;
		}
}

	// returns if not found!
	return -1;
}

// Prints the Array
void printArray(int arr[], int size) {

	for (int i = 0; i < size; i++) cout << arr[i] << " ";

	cout << endl;
}

int main() {
	int size;
	int key;
	int found;
	double startTime;
	double endTime;

	cout << "Enter the size of the random array" << endl;
	cin >> size;

	//int* arr = randArr(size, 0, 100);
	vector<int> vec = randVec(size, 0, 100);
	//cout << "Original array: " ;
	//printArray(arr, size);


				/*Different Sorters*/
////////////////////////////////////////////////////////////
	startTime = getTimeInSeconds();
	quickSort(vec, 0, vec.size() - 1);
	//radixSort(arr, size);
	//selectionSort(arr, size);
	//InsertionSort(arr, size);
	//quickSort(arr, size);
	//bubbleSort(arr, size);
	//sort(arr, arr + size);	//in built function
	//mergeSort(arr, 0, size - 1);

	endTime = getTimeInSeconds();

	cout << "Time taken for sorting: " << (endTime - startTime) << " seconds" << endl;

	/*Print Array*/
	//cout << "Sorted array: ";
	//printArray(arr, size);

	cout << "What number would you like to search for?" << endl;
	cin >> key;

	
	startTime = getTimeInSeconds();
	//found = LinearSearch(arr, size, key);
	//found = binarySearch(arr, size, key);

	endTime = getTimeInSeconds();

	cout << "Time taken for Searching: " << (endTime - startTime) << " seconds" << endl;

	/*if (key == -1) {
		cout << "Key not Found!";
	}
	else {
		cout << "The Key is found at index: " << found << endl;
	}*/
	return 0;
}

