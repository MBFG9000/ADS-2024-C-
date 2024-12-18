#include <vector>
#include <iostream>

using namespace std;

int BinarySearch(vector <int>& vec, int target){

    int start = 0, end = vec.size() - 1, mid;

    while (start <= end){

        mid = start + (end - start) / 2;

        if(vec[mid] == target){
            return mid;
        }

        if(vec[mid] > target){

            end = mid - 1;

        }else{

            start = mid + 1;

        }
        
    }

    return -1;

}
