#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int size, max;

	cout << "size: ";
	cin >> size;

	int *a = new int[size];

	cout << "array: ";
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	max = a[0];
	for (int i = 1; i < size; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int *aux = new int[max + 1];

	for (int i = 0; i < max + 1; i++)
	{
		aux[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		aux[a[i]]++;
	}

	int k = 0;
	for (int i = 0; i < max + 1; i++)
	{
		while (aux[i] > 0)
		{
			a[k] = i;
			k++;
			aux[i]--;
		}
	}

	cout << endl << "sorted array: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ' ';
	}

    return 0;
}