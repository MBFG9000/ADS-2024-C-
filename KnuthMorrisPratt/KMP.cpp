#include <iostream>
#include <vector>

using namespace std;

vector <int> PrefixFunction(string& s){
    
    int strsize = s.size(), j; 
    vector <int> prefix(strsize);

    prefix[0] = 0; 
    
    for (int i = 1; i < strsize; i++){
        j = prefix[i - 1];

        while (j > 0 && s[i] != s[j]){
            j = prefix[j-1];
        }

        if(s[i] == s[j]){
            j++;
        }

        prefix[i] = j;

    }
    
    return prefix;
}

vector <int> KMP(string& word, string& pattern){

    string s = pattern + '#' + word;

    vector <int> p = PrefixFunction(s); int patternsize = pattern.size();
    vector <int> result;

    for (int i = 0; i < p.size(); i++){
        
        if(p[i] == patternsize){

            result.push_back(i - patternsize * 2); 
        }
    }
    
    return result;
}


int main(){
    string s = "aaabdsabdsbebabaaaaaabababsd", t = "aaab";
    
    vector <int> result = KMP(s, t);


    for(int i : result){
        cout << i << ' ';
    }
    return 0;
}