#include "quick.cpp"
#include "heap.cpp"
#include <chrono>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;


void printVector(vector<int>& data) {
	cout << "Random values are: ";
	for (int i = 0; i < data.size(); i++) {
		cout << data.at(i) << ' ';
	}
}

int main(void) {
	vector<int> data{};

	int DATA_SIZE = 2;

	// a simple random generator to produce data from 0 to 99 with a container size of 12

	srand(time(0));

	for (int i = 0; i < DATA_SIZE; i++) {
		data.push_back(rand() % 100);
	}

	// print values
	printVector(data);
	cout << endl;

	auto start_lv = chrono::high_resolution_clock::now(); // get time before starting algorithm
	// testing Las Vegas approach
	quickSort(data);

	auto stop_lv = chrono::high_resolution_clock::now(); // get time once algorithm is done
	auto duration_lv = chrono::duration_cast<chrono::microseconds>(stop_lv - start_lv); // calculate duration
	cout << "Las Vegas: " << duration_lv.count() << " microseconds" << endl;

	auto start_bf = chrono::high_resolution_clock::now();
	// testing Brute Force approach
	heapPermutation(data, data.size() - 1, data.size() - 1);

	auto stop_bf = chrono::high_resolution_clock::now();
	auto duration_bf = chrono::duration_cast<chrono::microseconds>(stop_bf - start_bf);
	cout << "Brute Force: " << duration_bf.count() << " microseconds" << endl;

	return 0;
}
