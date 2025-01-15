#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU{

private:
    int* parent;
    int* rank;
public:
    DSU(int size){
        
        parent = new int[size];
        rank = new int[size];

        for (int i = 0; i < size; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i){
        if(parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]); //it makes path to boss of set shorter
    }

    void merge(int x, int y){

        int s1 = find(x);
        int s2 = find(y);

        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
            }
            else if(rank[s1] > rank[s2]){
                parent[s2] = s1;
            }
            else{
                parent[s2] = s1;
                rank[s1]++;

            }
        }
    }
};

class Graph {

private:
    vector<vector<int>> EdgeList;
    int V;
public:
    Graph(int V){
        this->V =V;
    }

    void addEdge(int x, int y, int w)
    {
        EdgeList.push_back({ w, x, y });
    }

    void kruskals_mst()
    {

        sort(EdgeList.begin(), EdgeList.end());

        DSU s(V);

        int ans = 0; int count = 0;  
        
        cout << "Following are the edges in the constructed MST"<< endl;

        for (auto edge : EdgeList) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];


            if (s.find(x) != s.find(y)) {
                
                s.merge(x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w << endl;
                count++;
            }
            
            if (count == V - 1) {
                break;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans;
    }
};

