#include <iostream>

using namespace std;

struct Node {   //структура узла где есть data - информация и поинтер на следующий элемент
    int data;  
    Node* next = nullptr;
};

class LinkedList{  //класс 

private:
    Node* head = nullptr;

public:
//конструктор особенность - нет типа возвращаемых данных имеет то же названия что и класс
//запускает при инициализации.
    LinkedList() {
        head = nullptr;
    } 
    
    // push method

    void push(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if(head == nullptr){
            head = newNode;
        }else{
            Node* current = head;
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = newNode; 
        }
    }

      int pop(){
        if(head == nullptr){
            cout << "List is empty" << endl;
            return -1;  
        }
        else{
            int element = head->data;
            Node* temp = head;
            head = head ->next;
            delete temp;
            return element;
        }
    }

    bool IsEmpty(){
        return (head == nullptr);
    }
};


int main(){

    int temp, size; LinkedList Llist;
    cin >> size;
    for (int i = 0; i < size; i++){
        cin >> temp;
        Llist.push(temp);
    }

    while(!Llist.IsEmpty()){
        cout << Llist.pop() << " ";
        
        if(!Llist.IsEmpty()){
            Llist.pop();
        }
    }    

    return 0;
}
