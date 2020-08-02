#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void swap(int* p1, int* p2);
void quicksort(int* arr, int start, int end);

int main()
{
	int arr[10000];
	int num = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < num; i++) {
		arr[i] = i+1;
	}
	for (int i = 0; i < num; i++) {
		swap(&arr[rand() % num], &arr[rand() % num]);
	}

	clock_t t1 = clock();

	quicksort(arr, 0, num - 1);

	clock_t t2 = clock();

	//for (int i = 0; i < num; i++) cout << arr[i] << " ";

	cout << endl;
	cout << "Executed time : " << t2 - t1 << "ms" << endl;

	return 0;
}
void swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void quicksort(int* arr, int start, int end)
{
	if (start >= end) {
		return;
	}

	int i = start + 1, j = end;
	int pivot = arr[start];
	
	while (i < j) {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot && j>start) {
			j--;
		}
		if (i < j) {
			swap(&arr[i], &arr[j]);
		}
		else
		{
			swap(&arr[j], &arr[start]);
		}
	}

	quicksort(arr, start, j - 1);
	quicksort(arr, j + 1, end);	
}
