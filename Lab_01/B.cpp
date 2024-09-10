#include "iostream"
#include "stack"
#include "vector"
using namespace std;

//WARNING: say Bismillah before working
//shit by mishanya bfg


int main(){
    int size; 
    cin >> size;
    
    vector <int> age(size);
    stack <int> st;


    for (int i = 0; i < size; i++){
        cin >> age[i];
    }

    vector<int> rslt(size, -1);

    for (int i = 0; i < size; i++){
        
        while(!st.empty() && age[st.top()] > age[i]){
            st.pop();
        }

        if(!st.empty()){
            rslt[i] = age[st.top()];
        }
        st.push(i); // вот этот участок меня напрегает разве мы не тярем значения ведь мы их удаляем потом не добавляем
    }

    for(auto i:rslt){
        cout << i << " ";
    }

    return 0;
}