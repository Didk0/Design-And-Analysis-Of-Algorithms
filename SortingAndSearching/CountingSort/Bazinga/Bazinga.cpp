#include <iostream>
#include <string>
using namespace std;

bool isBazinga(char ch)
{
	return ch == 'b' || ch == 'a' || ch == 'z' || ch == 'i' || ch == 'n' || ch == 'g' ||
		ch == 'B' || ch == 'A' || ch == 'Z' || ch == 'I' || ch == 'N' || ch == 'G';
}

int main()
{
	//условие: https://action.informatika.bg/problems/119

	int occurs[27] = { 0, };
	string input;
	getline(cin, input);

	for (size_t i = 0; i < input.size(); i++)
	{
		if (isBazinga(input[i]))
		{
			if (input[i] >= 'a' && input[i] <= 'z')
				occurs[abs(input[i] - 'a')]++;
			else
				occurs[abs(input[i] - 'A')]++;
		}
	}

	int min = 1000;

	for (int i = 0; i < 27; i++)
	{
		if (isBazinga(i + 'a'))
		{
			if (i == 0)
				min = std::min(min, occurs[i] / 2);
			else
				min = std::min(min, occurs[i]);
		}
	}

	cout << min;

	return 0;
}