
#include <iostream>

//GOVNOKOD

using namespace std;

int main(){
    int size , counter = 1; cin >> size;
    string students [size], prev;

    cin >> students[0]; prev = students[0];

    for (int i = 1; i < size; i++){
        cin >> students[i];
        if(prev != students[i]){
            counter++;
        }
        prev = students[i];
    }
    
    cout << "All in all: " << counter << "\nStudents:\n";

    cout << students [size - 1] << endl;

    prev = students [size - 1];
    for (int i = size - 2; i >= 0; i--){
        if(prev != students[i]){
            cout << students[i] << endl;
        }
        prev = students[i];
    }
    
    


    return 0;
}