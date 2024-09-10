#include <iostream>
#include <cmath>

using namespace std;
//WARNING: say Bismillah before working
//shit by mishanya bfg


/*
Dzhankieva B. N. legend
есть такое свойство что числа меньше sqrt(n) 
только могут являться простыми делителями
ибо попарно либо числа равны либо одно меньше и одно больше
то есть нам достаточно проверить числа только до sqrt(n)
что ускорить алгоритм 
*/
bool IsPrime(int n){
     if (n == 1 || n == 0) 
          return false;
     else if(n ==2)
          return true;

     for (int i = 2; i <= ceil(sqrt(n)); i++)
     {
          if(n%i == 0){
               return false;
          }
     }
     
     return true;
}


int main(){
     int n;cin >> n;
     if(IsPrime(n))
          cout << "YES";
     else
          cout << "NO";

}