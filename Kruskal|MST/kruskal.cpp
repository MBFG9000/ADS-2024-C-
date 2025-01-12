#include <iostream>

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
            
        }
    }
};

