#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int merged[100000];
int arr[100000];
int inversions;

void merge(int arr[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int ind = 0;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			merged[ind++] = arr[i++];
		else if (arr[i] > arr[j])
		{
			merged[ind++] = arr[j++];
			inversions += (mid - i + 1);
		}
	}

	while (i <= mid)
		merged[ind++] = arr[i++];

	while (j <= right)
		merged[ind++] = arr[j++];

	for (int k = left; k <= right; k++)
		arr[k] = merged[k - left];
}

void mergeSort(int arr[], int left, int right)
{
	if (left >= right) return;

	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);

	merge(arr, left, mid, right);
}

int main()
{
	// условие: https://action.informatika.bg/problems/128

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	mergeSort(arr, 0, n - 1);

	cout << inversions;

	return 0;
}