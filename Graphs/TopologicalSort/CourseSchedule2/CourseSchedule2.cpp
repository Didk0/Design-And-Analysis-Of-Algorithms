#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // условие: https://leetcode.com/problems/course-schedule-ii/

    /*vector<vector<int>> prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]];

    int inDegrees[2000];

    vector<int> findOrder(int numCourses, vector<vector<int>>&prerequisites)
    {
        vector<int> graph[2000];

        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegrees[prerequisites[i][0]]++;
        }

        vector<int> topSort;

        for (int i = 0; i < numCourses; i++)
        {
            if (inDegrees[i] == 0)
                topSort.push_back(i);
        }

        for (int i = 0; i < topSort.size(); i++)
        {
            int curr = topSort[i];
            for (int i = 0; i < graph[curr].size(); i++)
            {
                inDegrees[graph[curr][i]]--;

                if (inDegrees[graph[curr][i]] == 0)
                    topSort.push_back(graph[curr][i]);
            }
        }

        return topSort.size() == numCourses ? topSort : vector<int>();
    }*/

    return 0;
}