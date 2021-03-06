#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <conio.h>
#include <Windows.h>

#undef max

using namespace std;

void BogoSort(int *a, int size, int *iterations);
void CountingSort(int *a, int size, int *iterations);
void InsertionSort(int *a, int size, int *iterations);
void MergeSort(int *a, int beg, int end, int *iterations); //beg = 0, end = size - 1
void PancakeSort(int *a, int size, int *iterations);
void Quicksort(int *a, int left, int right, int *iterations); //left = 0, right = size - 1
void SelectionSort(int *a, int size, int *iterations);

//auxilary functions
bool IsSorted(int *a, int size);
int GetInt();
void FillArray(int *a, int size);
void FillArrayRandom(int *a, int size);
void DisplayArr(int *a, int size);

int main()
{ 
	int size, SortChoise, BreakLoop = 0, RandomFilling = 0, iterations, StartTime, EndTime, *a = nullptr;
	bool AllocationFail = true;
	//double iterations;

	while (true)
	{
		iterations = 0;
		cout << "Chose what sort to use: \n 1 - Insertion Sort \n 2 - Selection Sort \n 3 - Merge Sort \n 4 - Quick Sort \n 5 - Counting Sort \n 6 - Pancake Sort \n 7 - Bogo Sort \n\n";
		SortChoise = _getch();

		while (SortChoise > 55 || SortChoise < 49)
		{
			cout << "Use numbers from 1 to 7." << endl;
			SortChoise = _getch();
		}
		SortChoise -= 48; //converting VIRTUAL_KEY_CODES to int

		while (AllocationFail)
		{
			AllocationFail = false;

			cout << "Size of an array: ";
			size = GetInt();
			while (size < 1)
			{
				cout << "Size can range from 1 to 2147483647." << endl;
				size = GetInt();
			}

			try
			{
				a = new int[size];
			}
			catch (const bad_array_new_length)
			{
				cout << "It's impossible to allocate memory for your array, try smaller size." << endl;
				AllocationFail = true;
			}
		}
		AllocationFail = true;

		cout << "Use 0 for filling by hand, any other key for random filling." << endl << endl << "========================================" << endl;
		RandomFilling = _getch();

		if (RandomFilling != 48)
		{
			FillArrayRandom(a, size);
		}

		else
		{
			FillArray(a, size);
		}

		StartTime = clock();
		switch (SortChoise)
		{
		case 1: InsertionSort(a, size, &iterations); break;
		case 2: SelectionSort(a, size, &iterations); break;
		case 3: MergeSort(a, 0, size - 1, &iterations); break;
		case 4: Quicksort(a, 0, size - 1, &iterations); break;
		case 5: CountingSort(a, size, &iterations); break;
		case 6: PancakeSort(a, size, &iterations); break;
		case 7: BogoSort(a, size, &iterations); break;

		default: cout << "use numbers from 1 to 7" << endl;	break;
		}
		EndTime = clock();

		DisplayArr(a, size);

		cout << "Elapsed time: " << EndTime - StartTime << "ms \n";
		if (iterations < 0)
		{
			cout << "Number of iterations exceeded " << INT_MAX << "\n======================================== \n\n";
		}

		else
		{
			cout << "Number of iterations: " << iterations << "\n======================================== \n\n";
		}

		cout << "Press any key to continue, 0 to exit." << endl;
		BreakLoop = _getch();
		
		delete[] a;

		if (BreakLoop == '0')
		{
			break;
		}

		cout << endl << endl << endl;
	}
	
    return 0;
}

void BogoSort(int *a, int size, int *iterations) {
	int temp, randomIndex;

	while (!IsSorted(a, size)) {

		(*iterations)++;
		for (int i = 0; i < size; i++) {
			randomIndex = rand() % size;
			temp = a[i];
			a[i] = a[randomIndex];
			a[randomIndex] = temp;
		}

	}
}

void CountingSort(int *a, int size, int *iterations) {

	int max = a[0];
	for (int i = 1; i < size; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int min = a[0];
	for (int i = 1; i < size; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	if (min < 0)
	{
		int *aux = new int[abs(min) + max + 1];

		for (int i = 0; i < abs(min) + max + 1; i++)
		{
			aux[i] = 0;
		}

		for (int i = 0; i < size; i++)
		{
			(*iterations)++;
			aux[a[i] + abs(min)]++;
		}

		int k = 0;
		for (int i = 0; i < abs(min) + max + 1; i++)
		{
			(*iterations)++;
			while (aux[i] > 0)
			{
				a[k] = i + min;
				k++;
				aux[i]--;
			}
		}

		delete[] aux;
		return;
	}

	int *aux = new int[max + 1];

	for (int i = 0; i < max + 1; i++)
	{
		aux[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		(*iterations)++;
		aux[a[i]]++;
	}

	int k = 0;
	for (int i = 0; i < max + 1; i++)
	{
		(*iterations)++;
		while (aux[i] > 0)
		{
			a[k] = i;
			k++;
			aux[i]--;
		}
	}

	delete[] aux;
}

void InsertionSort(int *a, int size, int *iterations) {

	int temp;

	for (int i = 1; i < size; i++)
	{
		for (int k = i, j = i - 1; j >= 0;)
		{
			(*iterations)++;
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

}

void MergeSort(int *a, int beg, int end, int *iterations) {

	if (beg < end)
	{
		int mid = (beg + end) / 2;


		int* a1 = new int[mid + 1];
		int* a2 = new int[end - mid];

		int i = 0, j = 0, k = beg;
		for (int i = 0; i < mid + 1; i++)
		{
			(*iterations)++;
			a1[i] = a[i];
		}

		for (int i = 0; i < end - mid; i++)
		{
			(*iterations)++;
			a2[i] = a[mid + 1 + i];
		}

		MergeSort(a1, 0, mid, iterations);
		MergeSort(a2, 0, end - mid - 1, iterations);

		for (; i < mid + 1 && j < end - mid; k++)
		{
			(*iterations)++;
			if (a1[i] <= a2[j])
			{
				a[k] = a1[i];
				i++;
			}

			else
			{
				a[k] = a2[j];
				j++;
			}
		}

		while (i < mid + 1)
		{
			(*iterations)++;
			a[k] = a1[i];
			k++;
			i++;
		}

		while (j < end - mid)
		{
			(*iterations)++;
			a[k] = a2[j];
			k++;
			j++;
		}

		delete[] a1;
		delete[] a2;
	}

}

void PancakeSort(int *a, int size, int *iterations) {

	int maxInd, tempSize = size - 1, temp;

	while (tempSize > 0)
	{
		maxInd = 0;
		for (int i = 1; i < tempSize + 1; i++)
		{
			if (a[i] > a[maxInd])
			{
				maxInd = i;
			}
		}

		for (int i = 0, limit = maxInd; i <= maxInd / 2; i++, limit--)
		{
			(*iterations)++;
			temp = a[i];
			a[i] = a[limit];
			a[limit] = temp;
		}


		for (int i = 0, limit = tempSize; i <= tempSize / 2; i++, limit--)
		{
			(*iterations)++;
			temp = a[i];
			a[i] = a[limit];
			a[limit] = temp;
		}

		tempSize--;
	}

}

void Quicksort(int *a, int left, int right, int *iterations)
{
	int pivot, temp;
	int i, j;

	pivot = a[(left + right) / 2];
	for (i = left, j = right; i <= j; )
	{
		if (a[i] >= pivot && pivot >= a[j])
		{
			(*iterations)++;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			i++;
			j--;
		}

		else
		{
			if (a[i] < pivot)
			{
				i++;
			}

			if (a[j] > pivot)
			{
				j--;
			}
		}
	}

	if (left < j)
	{
		Quicksort(a, left, j, iterations);
	}

	if (right > i)
	{
		Quicksort(a, i, right, iterations);
	}
}

void SelectionSort(int *a, int size, int *iterations) {
	int min_index, temp;

	for (int i = 0; i < size - 1; i++) {

		min_index = i;

		for (int k = i; k < size; k++) {

			(*iterations)++;
			if (a[k] < a[min_index]) {
				min_index = k;
			}

		}

		temp = a[i];
		a[i] = a[min_index];
		a[min_index] = temp;

	}

}

bool IsSorted(int *a, int size) {

	for (int i = 0; i < size - 1; i++) {

		if (a[i] > a[i + 1]) {
			return false;
		}
	}

	return true;
}

int GetInt() {

	SetConsoleCtrlHandler(NULL, true); //removes CTRL+C from signal processing 
	
	int data;
	char test = '\n';
	cin >> data;

	while (!cin)
	{
		cout << "Only integers are allowed. Try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> data;
	}

	while (cin.peek() != '\n')
	{
		cout << "Only integers are allowed. Try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> data;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return data;
}

void FillArray(int *a, int size) {

	cout << "Unsorted array: ";
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];

		if (!cin)
		{
			cout << "Wrong input, array can contain only integers ranging from -2147483648 to 2147483647. Type array from the beginning again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			i = -1;
			continue;
		}
	}
}

void FillArrayRandom(int *a, int size) {

	srand(time(NULL));

	cout << "Unsorted array: ";
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 101;
		cout << a[i] << " ";
	}
	cout << endl;
}

void DisplayArr(int *a, int size) {

	cout << "Sorted array: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

}
