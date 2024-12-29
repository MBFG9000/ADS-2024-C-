#include <iostream>
#include <vector>
#include <random>

using namespace std;

random_device rd;
mt19937 gen(rd());

int partition(vector <int>& vec, int& start, int& end){
    
    uniform_int_distribution<> distrib(start, end);
    int pivot = distrib(gen);
    
    swap(vec[pivot],vec[end]);
    pivot = vec[end];

    int i = start - 1;

    for (int j = start; j <= end - 1; j++){
        
        if(vec[j] < pivot){
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i+1],vec[end]);

    return i+1;
    

}

void QuickSort(vector <int> & vec, int start, int end){

    if(start < end){

        int pivot_idx = partition(vec, start, end);

        QuickSort(vec, start, pivot_idx - 1);
        QuickSort(vec, pivot_idx + 1, end);

    }
}



