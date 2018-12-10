// Bogosort

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

void shuffle(int *a, int size) {
	int temp, randomN;
	for (int i = 0; i < size; i++) {
		randomN = rand() % size;
		temp = a[i];
		a[i] = a[randomN];
		a[randomN] = temp;
	}
}

void sortcheck(int *a, int size, bool *sorted) {
	int i;
	for (i = 0; i < size - 1; i++) {
		if (a[i] > a[i + 1]) {
			break;
		}
	}

	if (i == size - 1) {
		*sorted = true;
	}
}

int main()
{
	srand(time(0));
	int size, i, iterations = 0, start_time, end_time;
	bool sorted = false;
	
	cout << "Type in size of an array(>=1): ";
	cin >> size;

	int* a = new int[size];

	for (i = 0; i < size; i++) {
		cout << "Type in an element: ";
		cin >> a[i];
	}

	start_time = clock();
	cout << endl << "unsorted array: ";
	for (i = 0; i < size; i++) {
		cout << a[i] << " ";		
	}
	cout << endl;

	while (sorted == false){

		shuffle(a, size);

		sortcheck(a, size, &sorted);

		iterations++;	
	}

	cout << "sorted array: ";
	for (i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl << endl;

	end_time = clock();
	start_time = end_time - start_time;

	cout << "number of iterations: " << iterations << endl;
	cout << "elapsed time: " << start_time << "ms" << endl << endl;
	delete[] a;
    return 0;
}

