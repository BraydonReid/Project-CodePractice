#include<random>

using namespace std;


int RandomNumber(int min, int max) {
	random_device rd;
	mt19937 gen(rd());

	// Define the range for the random numbers (1-9)
	uniform_int_distribution<int> distribution(min, max);

	// Generate and print 1 random numbers
	int random_number = distribution(gen);

	return random_number;
}

 
