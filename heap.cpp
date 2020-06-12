#include <iostream>
#include <vector>
using namespace std;

/* brute force approach using a permutation algorithm*/

void printArr(vector<int>& data)
{
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void heapPermutation(vector<int>& data, int size, int n)
{
    // if size becomes 1 then prints the obtained
    // permutation
    if (size == 1)
    {
        printArr(data);
        return;
    }

    for (int i = 0; i < size; i++)
    {
        heapPermutation(data, size - 1, n);

        // if size is odd, swap first and last
        // element
        if (size % 2 == 1)
            swap(data[0], data[size - 1]);

        // If size is even, swap ith and last
        // element
        else
            swap(data[i], data[size - 1]);
    }
}
