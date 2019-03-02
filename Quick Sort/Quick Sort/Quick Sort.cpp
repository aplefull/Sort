#include "stdafx.h"
#include <iostream>

using namespace std;

void quicksort(int*, int, int);

int main()
{
	int size;
	cout << "size: ";
	cin >> size;

	
	int *a = new int[size];

	cout << "array: ";
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	quicksort(a, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ' ';
	}

	delete[] a;
    return 0;
}

void quicksort(int *a, int left , int right)
{
	int pivot, temp;
	int i, j;

	pivot = a[(left + right) / 2];
	for (i = left, j = right; i <= j; )
	{
		if (a[i] >= a[pivot] && a[pivot] >= a[j])
		{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			i++;
			j--;
		}

		else
		{
			if (a[i] < a[pivot])
			{
				i++;
			}

			if (a[j] > a[pivot])
			{
				j--;
			}
		}
	}

	if (left < j)
	{
		quicksort(a, left, j);
	}

	if (right > i)
	{
		quicksort(a, i, right);
	}
}
