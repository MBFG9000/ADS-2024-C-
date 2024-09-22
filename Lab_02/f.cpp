#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next = nullptr;
};

class LinkedList{
    private:
        Node* head = nullptr;
        int size = 0;
    public:
        void push_back(int value){
            Node* newNode = new Node();
            newNode-> data = value;
            newNode-> next = nullptr;

            if(head == nullptr){
                head = newNode;
            }else{
                Node* current = head;
                while(current->next != nullptr){
                    current = current->next;
                }

                current->next = newNode;
            }

            size++;

        }
        
        void insert_at(int param, int index){
            if(index  < 0 || index > size){
                cout << "index " << index << " is out of range";
                return;
            }

            Node* newNode = new Node();
            newNode->data = param;
            
            if(index == 0){

                newNode->next = head;
                head = newNode;
            }            
            else{

                Node* current = head;

                for (int i = 0; i < index - 1; i++){
                    current = current->next; 
                } 
                
                newNode-> next = current-> next;
                current-> next = newNode;
            }
           
           size++;
        }

        void display(){
            Node* current = head;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            
        }
};

int main(){
    LinkedList Llist; int size, temp, index;

    cin >> size;

    for (int i = 0; i < size; i++){
        cin >> temp;
        Llist.push_back(temp);
    }

    cin >> temp >> index;

    Llist.insert_at(temp, index);

    Llist.display();
    

}
