#include <iostream>
#include <cstring>
using namespace std;

//WARNING: say Bismillah before working
//shit by mishanya bfg

int NthPrime(int n){

     //Algorithm - sieve of eratosthenes 
     bool IsPrime[1000005]; memset(IsPrime, 1, sizeof(IsPrime));
     IsPrime[0] = IsPrime[1] = false;
     int counter = 0, primecounter = 0;
     for (int i = 2; i < 1000005; i++){
          if(IsPrime[i]){
               /*есть такое свойство что
               1. Если у числа есть делитель, который больше 1 и меньше самого , то этот
               делитель должен быть парой с другим числом. Например, если возьмем 36 , то его
               делитель 6 связан с 6, потому что 6*6 =36.
               2. Если у числа есть делитель больше корня этого числа , то его пара будет меньше корня . Например,
               для 36 , если у нас есть делитель 9, то 36/9 = 4, и 4 меньше 6.
               3. Следовательно, если число не делится на числа от 2 до корня этого числа, это означает, что у нет
               делителей, и оно должно быть простым.
               */  
               // учитывая  этот принцип можно начинать с квадрата числа
               // ну то есть условно 2*3 и шесть ушло и лучше начать с 9 сразу когда будем проверять 3 ведь мы уже учли вариант с 2 
               for (int j = i*i; j < 1000005; j += i){
                    IsPrime[j] = false;
               }
               counter++;
               if(IsPrime[counter]){
                    primecounter++;
               }
          }
          if(primecounter == n){
               return i;
          }          

     }
     
     return 0;

}
int main(){
     int n;
     cin >> n;
     
     cout << NthPrime(n);
     



     return 0;
}