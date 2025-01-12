#include <iostream>
#include <cmath>

using namespace std;

int CharacterHash(char character){
    
    character = tolower(character);
    return character - 'a' + 1;
}

int Hash(string& word, const int& P, const int& mod){
    int h = 0;

    for (char c : word){
        
        h = (h * P + CharacterHash(c)) % mod;
    }
    
    return h;
}

int power(int a, int b){
    int result = a;
    for (int i = 1; i < b; i++)
    {
        result  = result * a;
    }
    
    return result;
}

int main(){
    string s = "aaabdsabdsbebabaaaaaabababsd", t = "aaab";
    int n = s.size(), m = t.size();
    

    const int P = 29, mod = 997;

    
    string word = s.substr(0,m);
    int patternHash = Hash(t, P, mod), wordHash = Hash(word, P, mod);
    

    for (int i = m; i < n; i++){
        
        if(wordHash == patternHash){

            cout << i - m << " ";
        }

        wordHash = (( wordHash - (( power(P, m - 1) * CharacterHash(s[i - m]) )% mod) + mod ) * P + CharacterHash(s[i])) % mod;
    }
    
    return 0;
}