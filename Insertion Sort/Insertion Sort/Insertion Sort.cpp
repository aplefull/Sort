#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int size, temp;
	cout << "size: ";
	cin >> size;

	int *a = new int[size];

	cout << "array: ";
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i < size; i++)
	{
		for (int k = i, j = i - 1; j >= 0;)
		{
			if (a[k] < a[j])
			{
				temp = a[k];
				a[k] = a[j];
				a[j] = temp;
				j--;
				k--;
			}

			else
			{
				break;
			}
		}
	}

	cout << "sorted array: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ' ';
	}

    return 0;
}

