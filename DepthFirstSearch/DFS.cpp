#include <iostream>
#include <vector>

using namespace std;

void DepthFirstSearch (vector<vector<int>>& adjlist, int& v, vector <bool>& visited){

    visited[v] = true;

    for(int u : adjlist[v]){

        if(!visited[u]){

            
            DepthFirstSearch(adjlist, u, visited);
        }
    }
}

void DepthFirstSearch(vector<vector<int>>& adjlist, int start){

    vector <bool> visited(adjlist.size());

    fill(visited.begin(), visited.end(), false);

    DepthFirstSearch(adjlist, start, visited);
}