#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeatingChar(int N, const vector<char>& stream) {
    unordered_map<char, int> freq;  
    queue<char> q;                  

    for (int i = 0; i < N; ++i) {
        char ch = stream[i];

        
        freq[ch]++;

        
        q.push(ch);

        
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

       
        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;  
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<char> stream(N);
        for (int i = 0; i < N; ++i) {
            cin >> stream[i];
        }

        firstNonRepeatingChar(N, stream);
    }

    return 0;
}