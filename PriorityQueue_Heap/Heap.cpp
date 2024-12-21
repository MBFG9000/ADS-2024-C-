#include <iostream>
#include <vector>

using namespace std;
/*
    (v)
    / \
(2v+1) (2v+2)

*/

void heapify_down(int& v, vector<int>& heap){
    int u = v;

    if(2*v+1 < heap.size() && heap[2*v + 1] > heap[u]){
        u = 2*v + 1;
    }
    if(2*v+2 < heap.size() && heap[2*v + 2] > heap[u]){
        u = 2*v + 2;
    }

    if(u == v){
        return;
    }

    swap(heap[v],heap[u]);

    heapify_down(u, heap);
}

void BuildHeap(vector<int>& heap){
    
    for (int i = heap.size() / 2 - 1; i >= 0; i--){
        heapify_down(i,heap);    
    } 

}
void heapify_up(int& v, vector <int>& heap){
    
    while(v!=0 && heap[(v - 1)/ 2] < heap[v]){

        swap(heap[(v - 1)/ 2], heap[v]);
        v = (v - 1)/ 2;

    }
}

void push(int x, vector<int>& heap){
 
    heap.push_back(x);
    int index = (heap.size() - 1);

    heapify_up(index, heap);

}

void pop(vector<int>& heap){
    swap(heap[0], heap[heap.size() - 1]);

    heap.pop_back();
    

    int index = 0;

    heapify_down(index,heap);
}

int main(){


    return 0;
}