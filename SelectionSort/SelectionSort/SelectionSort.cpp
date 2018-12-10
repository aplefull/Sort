#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace	std;

void swap(int a[], int min_index, int i) {
	int temp;
	temp = a[i];
	a[i] = a[min_index];
	a[min_index] = temp;
}


int main()
{
	int i, size;
	srand(time(NULL));

	cout << "Type in size of an array(>=1): ";
	cin >> size;

	int* a = new int[size];

	for (i = 0; i < size; i++) {
		a[i] = rand() % 70;
	}

	//ввод вручную 
	/*for ( i = 0; i < size; i++){
		cout << "Type in value: ";
		cin >> a[i];
	}*/
		
	cout << "unsorted array: ";
	for (i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

	for (i = 0; i < size - 1; i++){

		int min_index = i;

		for (int k = i; k < size; k++) {

			if (a[k] < a[min_index]) {
				min_index = k;
			}

		}
			
		swap(a, min_index, i);

	}

	cout << endl << "sorted array: ";
	for (i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

	delete[] a;
    return 0;
}



