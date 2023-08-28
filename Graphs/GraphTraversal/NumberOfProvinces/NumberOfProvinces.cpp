#include <iostream>
#include <vector>
using namespace std;

bool visited[205];

void dfs(int vertex, vector<vector<int>>& graph)
{
    visited[vertex] = true;

    for (int i = 0; i < graph[vertex].size(); i++)
    {
        if (!visited[i] && graph[vertex][i] == 1)
        {
            dfs(i, graph);
        }
    }
}

int main()
{
    // условие: https://leetcode.com/problems/number-of-provinces/description/

    vector<vector<int>> isConnected = { {1, 1, 0},{1, 1, 0},{0, 0, 1} }; // every node is connected to itself

    int count = 0;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (!visited[i])
        {
            dfs(i, isConnected);
            count++;
        }
    }

    cout << count;

    return 0;
}
