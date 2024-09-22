#include <iostream>
#include <stdlib.h>

//GOVNOKOD

using namespace std;

int main(){
    int size, k; cin >> size;
    
    int* nums = new int[size];
    
    for(int i = 0; i < size; i++){
        cin >> nums[i];
    }
    
    cin >> k;

    for (int i = 0; i < size; i++){
        nums[i] = abs(nums[i] - k);
        
    }

    int index = 0;
    int min = 2147483647;
    for(int i = 0; i < size; i++){
        if(nums[i] < min){
            min = nums[i];
            index = i;
        }
    }

    cout << index;
    




    return  0;
}