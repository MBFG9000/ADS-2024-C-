#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

vector<int> BreadthFirstSearch(vector<vector<int>> adjlist, int source){
    
    vector<int> distance(adjlist.size());  int infinity = numeric_limits<int> :: max(), v;
    
    fill(distance.begin(), distance.end(), infinity);

    queue <int> Q; Q.push(source); distance[source] = 0;

    while(!Q.empty()){
        v = Q.front(); Q.pop();

        for(int u : adjlist[v]){

            if(distance[u] == infinity){
                distance[u] = distance[v] + 1;
                Q.push(u);
            }
        }

    }

    return distance;
}


int main(){

    vector<vector<int>> G;



    return 0;
}