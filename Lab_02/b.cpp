#include <iostream>
#include <deque>

//GOVNOKOD

using namespace std;

int main(){
    int size, pos; cin >> size >> pos;

    string temp;
    
    deque <string> poem;

    for (int i = 0; i < size; i++){
        cin >> temp;  
        poem.push_back(temp);
    }
    
    for (int i = 0; i < pos; i++){
        poem.push_back(poem.front());
        poem.pop_front(); 
    }
    
    for (auto i : poem){
        cout << i << " ";
    }
    


    return 0;
}