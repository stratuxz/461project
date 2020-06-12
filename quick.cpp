#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

/* implementation of Quick Sort as an example of the Las Vegas algorithm*/

void quickSortHelper(vector<int>& data, int start, int end) {
	// empty/bogus data set
	if (end < start) {
		return;
	}
	// base case 1: size 1
	if (end == start) {
		return;
	}
	// base case 2: size 2
	else if (end - start == 1) {
		// if last digit is greater than start, swap
		if (data[end] < data[start]) {
			int temp = data[end];
			data[end] = data[start];
			data[start] = temp;
		}
		// otherwise do nothing
	}

	int first_item = data[start];
	int last_item = data[end];
	int midpoint = (start + end) / 2;
	int mid_item = data[midpoint];

	/* select a pivot based on specific criteria */
	int pivot_index = start;

	// pivot becomes the midpoint
	//	 ex: 2 5 7										         ex: 9 4 2
	if (mid_item > first_item && mid_item < last_item || mid_item < first_item && mid_item > last_item)
	{
		pivot_index = midpoint;
	}
	// pivot becomes end
	//			 ex: 3 20 10										ex: 16 3 9
	else if (last_item > first_item && last_item < mid_item || last_item < first_item && last_item > mid_item)
	{
		pivot_index = end;
	}

	//swap pivot with last item
	int pivot_value = data[pivot_index];
	data[pivot_index] = data[end];
	data[end] = pivot_value;

	/* the algorithm put in place */
	int i = start;
	int j = end - 1;

	while (i < j)
	{
		while (data[i] < pivot_value && i < j)
		{
			i++;
		}
		while (data[j] > pivot_value && i < j)
		{
			j--;
		}
		if (i < j)
		{
			int temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	//swap pivot back
	int temp = data[i];
	data[i] = data[end];
	data[end] = temp;

	// recursively repeat
	quickSortHelper(data, start, i - 1);
	quickSortHelper(data, i + 1, end);
}


void quickSort(vector<int>& data) {
	quickSortHelper(data, 0, data.size() - 1);
}
