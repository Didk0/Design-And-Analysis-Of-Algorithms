#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // условие: https://leetcode.com/problems/course-schedule/

    /*int inDegree[2000];
    bool canFinish(int numCourses, vector<vector<int>>&prerequisites)
    {
        vector<vector<int>> gr(numCourses + 1);
        int m = prerequisites.size();

        for (int i = 0; i < m; i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            inDegree[a]++;
            gr[b].push_back(a);
        }

        vector<int> topSort;

        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
                topSort.push_back(i);
        }

        for (int i = 0; i < topSort.size(); i++)
        {
            int curr = topSort[i];

            for (int i = 0; i < gr[curr].size(); i++)
            {
                inDegree[gr[curr][i]]--;

                if (inDegree[gr[curr][i]] == 0)
                    topSort.push_back(gr[curr][i]);
            }
        }

        return topSort.size() == numCourses;
    }*/

    return 0;
}
