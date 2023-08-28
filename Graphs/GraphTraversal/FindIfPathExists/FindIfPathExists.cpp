#include <iostream>
using namespace std;

int main()
{
    // условие: https://leetcode.com/problems/find-if-path-exists-in-graph/description/

    /*bool used[2 * 100005];
    vector<int> graph[2 * 100005];

    bool dfs(int source, int dest)
    {
        if (source == dest)
            return true;

        used[source] = 1;
        cout << source << endl;
        for (int i = 0; i < graph[source].size(); i++)
        {
            if (!used[graph[source][i]])
                if (dfs(graph[source][i], dest))
                    return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>&edges, int source, int destination) {

        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        return dfs(source, destination);
    }*/

    return 0;
}
