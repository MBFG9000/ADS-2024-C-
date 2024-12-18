#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class Graph
{
private:

    vector <map<int, int>> adjlist;

public:

    Graph(int V){
        adjlist.resize(V);
    };

    void add_edge(int& u, int& v, int& w){
    //only make edge from u to v with weight:  u -w-> v
    
    int V = adjlist.size();

    if(u >= V || u < 0 || v >= V || v < 0 || w < 0){
        cout << "Error index out of range(That vertex doesnt exist)" << endl; return;
    }

    adjlist[u][v] = w; 

    }

    
    void print_adjlist(){

        for (int i = 0; i < adjlist.size(); i++){
            cout << i << ": ";

            for (const auto& pair : adjlist[i]){
                cout <<"("<< pair.first <<","<< pair.second <<") ";
            }

            cout << endl;
        }

    }    

    const vector <map<int, int>>& getadjlist () const{
        return adjlist;
    }

};

int findmin(bool was[], int d[], int& V){
    int min = INT32_MAX;
    int min_index = -1;

    for (int i = 0; i < V; i++){
        if(was[i] == false && d[i] < min){
            min = d[i];
            min_index = i;
        }
    }
    
    return min_index;
}




int main(){

    string filename = "input.txt"; 
    int V, v, w;

    ifstream file(filename);

    if(!file.is_open()){
        cerr << "Error: Unable to open " << filename << endl;
        return 1;
    }

    //cout << "How much vertices your Graph has: ";
    //cin >> V;

    file >> V;

    Graph graph(V);

    
    
    for (int i = 0; i < V; i++){
        //cout << "connect to " << i << " vertex:(format v w and -1 for stop connecting to current vertex)" << endl;
        
        while (1){
            //cin >> v;   
            file >> v; if (v == -1)  break; file >> w; 
            //cin >> w;

            graph.add_edge(i, v, w);
        }
    }

    graph.print_adjlist();

    vector <map<int, int>> G = graph.getadjlist();

    bool was[V];  
    int distance[V], u; 
    int parent[V];  

    for (int  i = 0; i < V; i++){
        was[i] = false;
        distance[i] = INT32_MAX;
        parent[i] = -1;
    }

    distance[0] = 0;

    for (int i = 0; i < V; i++){
        
        v = findmin(was, distance, V); 

        if(v == -1 || distance[v] == INT32_MAX){
            break;
        }

        was[v] = true;

        for (auto& pair : G[v]){
            u = pair.first;
            w = pair.second;

            if(distance[u] > distance[v] + w){
                
                distance[u] = distance[v] + w;
                parent[u] = v;

            }
        }

        
    }

    cout << endl;
    for (size_t i = 0; i < V; i++)
    {
        cout << distance[i] << " ";
    }
    
    


    return 0; 
}