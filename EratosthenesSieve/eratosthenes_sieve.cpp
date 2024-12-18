#include <vector>

using namespace std;

void EratosthenesSieve(int n){

    vector <bool> IsPrime (n + 1, true);

    IsPrime[0] = IsPrime[1] = false;

    for (int p = 2; p * p <= n; p++){
        
        if(IsPrime[p]){
            
            for (int i = p * p; i <= n; i= i + p){
                
                IsPrime[i] = false;

            }

        }

    }
    
}