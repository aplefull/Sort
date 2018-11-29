// Bogosort

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	int size, i, temp, randomN, n = 0, iterations = 0, start_time, end_time;
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
		//swap
		for (i = 0; i < size; i++) {
			randomN = rand() % size;
			temp = a[i];
			a[i] = a[randomN];
			a[randomN] = temp;
		}

		for (i = 0; i < size - 1; i++) {
			if (a[i] > a[i + 1]) {
				break;
			}
			else n++;		
		}

		if (n == size - 1) {
			sorted = true;
		}
		else n = 0;
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

