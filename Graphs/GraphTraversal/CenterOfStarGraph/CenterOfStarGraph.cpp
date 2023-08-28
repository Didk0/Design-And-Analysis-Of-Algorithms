#include <iostream>
using namespace std;

int main()
{
    // условие: https://leetcode.com/problems/find-center-of-star-graph/
    
    // I начин:
    /*if (edges[0][0] == edges[1][0])
        return edges[1][0];
    else if (edges[0][0] == edges[1][1])
        return edges[1][1];
    else
        return edges[0][1];*/

    // II начин:
    // vector<int> graph[100002];
    // for(int i=0; i<edges.size(); i++)
    // {
    //     graph[edges[i][0]].push_back(edges[i][1]);
    //     graph[edges[i][1]].push_back(edges[i][0]);
    // }

    // int vertex = 0;
    // for(int i=0; i<=edges.size()+1; i++)
    // {
    //     if(graph[i].size() == edges.size())
    //         vertex = i;
    // }

    // return vertex;

    return 0;
}
