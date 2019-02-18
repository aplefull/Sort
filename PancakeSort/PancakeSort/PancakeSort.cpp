#include "stdafx.h"
#include <iostream>

using namespace std;

void flip(int a[], int n) {
	int temp;
	int limit = n;
	for (int i = 0; i < limit / 2; i++, n--)
	{
		temp = a[i];
		a[i] = a[n - 1];
		a[n - 1] = temp;
	}
}

void pancakeSort(int a[], int size);

int main()
{
	int size;
	cout << "size: ";
	cin >> size;

	int *a = new int[size];

	cout << "unsorted array: ";

	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	pancakeSort(a, size);

	cout << "sorted array: ";

	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ' ';
	}

    return 0;
}

void pancakeSort(int a[], int size) {
	
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (a[i + 1] < a[i])
			{
				flip(a, i + 1);
				flip(a, i + 2);

			}
		}
	}
}