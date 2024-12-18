#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b){

    int temp = a;
    a = b;
    b = temp;

}

void BubbleSort(vector<int>& vec){
    
    int size = vec.size();

    for(int i = 0; i < size; i++){
    
        for (int j = 0; j < size - 1 ; j++){
            
            if(vec[j] > vec[j + 1]){
        
              swap(vec[j], vec[j+1]);

            }
        }
    }
}

/* Оптимизация:

1) Можно проверить выполнялись ли свапы(swap), ведь если на каком
то из шагов они остановились это значит что массив уже отсортирован.
Ведь если по условию нигде нет соседних элементов в неправильном порядке
то все элементы стоят по порядку.

2) Логический понятно что худший случай для алгоритма это когда массив в 
обратном порядке. Но даже прогнав алгоритм по этому варианту мы заметим что
максимум встает в самый конец еще на первой итерации ведь он сравнивается со 
всеми элементами или с элементами которые оказались меньше него но больше других.
То есть нам можно сокращать число проверок ведь мы знаем что конец массива 
выстраиваться точно правильно.

*/

void BubbleSort(vector<int>& vec){
    
    int size = vec.size(); bool swapped;

    for(int i = 0; i < size; i++){
        
        swapped = false;

        for (int j = 0; j < size - 1 - i ; j++){
            
            if(vec[j] > vec[j + 1]){
        
              swap(vec[j], vec[j+1]);
              swapped = true;

            }
        }

        if(swapped == false){
            break;
        }

    }
}