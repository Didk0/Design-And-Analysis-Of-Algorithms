#include <iostream>
#include <vector>
using namespace std;

int occurs[1002];

int main()
{
	//условие: https://leetcode.com/problems/relative-sort-array/

	vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
	vector<int> arr2 = { 2,1,4,3,9,6 };

	int pos = 0;

	for (int i = 0; i < arr1.size(); i++) {
		occurs[arr1[i]]++;
	}

	for (int i = 0; i < arr2.size(); i++) {
		while (occurs[arr2[i]] > 0) {
			arr1[pos++] = arr2[i];
			occurs[arr2[i]]--;
		}
	}

	for (int i = 0; i < 1002; i++) {
		while (occurs[i] > 0) {
			arr1[pos++] = i;
			occurs[i]--;
		}
	}

	return 0;
}
