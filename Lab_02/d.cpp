#include <iostream>
#include <map>

//GOVNOKOD

using namespace std;

int main(){
    map <int,int> mp;

    int size, temp, count = 0;

    cin >> size;

    for (int i = 0; i < size; i++){
        cin >> temp;
        mp[temp]++;
        if (mp[temp] > count){
            count = mp[temp];
        } 
    }

    for (auto it = mp.rbegin(); it != mp.rend(); ++it){
        if (it->second == count){
            cout << it->first << " ";
        }
    }
    

    

    return 0;
}