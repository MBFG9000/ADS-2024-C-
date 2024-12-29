#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int>& vec, vector<int>& MergeBuffer, int& start, int& end, int& mid){

    int lp = start, rp = mid + 1, i = 0, size = (end - start);
       
    while(lp <= mid && rp <= end){
        
        if(vec[lp] <= vec[rp]){
            MergeBuffer[i++] = vec[lp++];
        }else{
            MergeBuffer[i++] = vec[rp++];
        }
    }

    while(lp <= mid){
        MergeBuffer[i++] = vec[lp++];
    }

    while(rp <= end){
        MergeBuffer[i++] = vec[rp++];
    }

    for (int i = 0; i <= size; i++){
        
        vec[start + i] = MergeBuffer[i];
    }
    
}

void MergeSort(vector<int>& vec, vector<int>& MergeBuffer, int& start, int& end){
    
    if(start < end){

        int mid = start + (end - start) / 2;
        int mid_offset = mid + 1;

        MergeSort(vec, MergeBuffer, start, mid);
        MergeSort(vec, MergeBuffer, mid_offset, end);
        
        Merge(vec, MergeBuffer, start, end, mid);
    }

}

void MergeSort(vector <int>& vec){

    vector <int> MergeBuffer (vec.size());

    int start = 0, end = vec.size() - 1;

    MergeSort(vec, MergeBuffer, start, end);

}

int main(){
    vector <int> vec = {2,32,12,3,43,54,32,42,3,2,4,56,8,120};


    
    MergeSort(vec);

    for (auto i : vec){
        cout << i << " ";
    }
    
}