#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
	string name;
	int fn;
	int score;

	Student(string name = "", int fn = 0, int score = 0)
		: name(name), fn(fn), score(score)
	{}

	bool operator<(const Student& s)
	{
		return score < s.score || (score == s.score && fn < s.fn);
	}
};

Student students[100005];
int questions[100005];

int main()
{
	// условие: https://www.hackerrank.com/contests/daa-2021-2022-winter-1/challenges/challenge-2593/problem

	int studentsCount, questionsCount;
	cin >> studentsCount >> questionsCount;

	if (studentsCount < 1 || questionsCount < 1)
		return 1;

	for (int i = 0; i < studentsCount; i++)
		cin >> students[i].name >> students[i].fn >> students[i].score;
	for (int i = 0; i < questionsCount; i++)
		cin >> questions[i];

	sort(students, students + studentsCount);

	for (int i = 0; i < questionsCount; i++)
	{
		int left = 0, right = studentsCount - 1, mid;
		Student res = students[0];
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (students[mid].score >= questions[i])
			{
				res = students[mid];
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		cout << res.name << ' ' << res.fn;
		if (i < questionsCount - 1)
			cout << endl;
	}

	return 0;
}