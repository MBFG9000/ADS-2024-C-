#include <iostream>
#include <vector>

using namespace std;

void HeapifyDown(vector <int>& Heap, int& i, int& size){
    
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int current = i;

    if (left < size && Heap[current] < Heap[left]){
        current = left;
    }
    if(right < size && Heap[current] < Heap[right]){
        current = right;
    }

    if(current == i){
        return;
    }

    swap(Heap[current], Heap[i]);
    HeapifyDown(Heap, current, size);
}

vector <int> BuildHeap(vector <int> vec){
    int size = vec.size();

    for (int i = size/2 - 1; i >= 0; i--){

        HeapifyDown(vec, i, size);
    }
    
    return vec;

}

int pop(vector <int>& Heap){
    int size = Heap.size(), value, first = 0;

    swap(Heap[first], Heap[size - 1]);
    value = Heap[size - 1];

    Heap.pop_back(); size--;

    HeapifyDown(Heap, first, size);
    

    return value;
}

void HeapSort(vector <int>& vec){
    vector <int> Heap = BuildHeap(vec);

    int heapsize = Heap.size();

    vec.clear();

    for (int i = 0; i < heapsize; i++){
        vec.push_back(pop(Heap));
    }
    

}


int main(){
    vector <int> kek = {45,45,32,43,235,67,2,3,4,5,6,9};

    HeapSort(kek);

    for (auto i : kek)
    {
        cout << i << " ";
    }
    
}

