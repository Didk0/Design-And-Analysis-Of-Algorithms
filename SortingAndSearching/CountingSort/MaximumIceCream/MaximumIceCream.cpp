#include <iostream>
#include <vector>
using namespace std;

int occurs[100004];

int main()
{
	// условие: 

	vector<int> costs = { 1,3,2,4,1 };
	int coins = 7;

	int count = 0;

	for (int i = 0; i < costs.size(); i++)
		occurs[costs[i]]++;

	int ind = 0;
	for (int i = 0; i < 100004; i++)
	{
		while (occurs[i] > 0)
		{
			costs[ind++] = i;
			occurs[i]--;
		}
	}

	for (int i = 0; i < costs.size(); i++)
	{
		if (coins < costs[i])
			break;

		coins -= costs[i];
		count++;
	}

	cout << count;

	return 0;
}