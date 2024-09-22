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

        void pop_at(int index){
            if(index < 0 || index >= size){
                cout << "index " << index << " is out of range";
                return;
            }

            if(index == 0){
                Node* temp = head;
                head = head->next;
                delete temp;
            }else{

                Node* current = head;

                for (int i = 0; i < index-1; i++){
                    current = current->next;
                }
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;

            }

            size--;
        }

        void display(){
            if(size != 0){
            
            Node* current = head;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }

            }else{
                cout << -1;
            }
        }

        void replace(int p1, int p2){
            if(p1 < 0 || p2 < 0 || p1 >= size || p2 >= size){
                cout << "Index out of range";
                return;
            } 

            if(p1 == p2){
                return;
            }

            Node* Node1;

            if(p1 == 0){

                Node1 = head;
                head = head->next;
            }else{

                Node* prev1 = head;

                for (int i = 0; i < p1 - 1; i++){
                    prev1 = prev1->next;
                }

                Node1 = prev1->next;
                prev1->next = Node1->next;    
            }

            if(p2 == 0){
                Node1->next = head;
                head = Node1;
            }else{
        
                Node* prev2 = head;

                for (int i = 0; i < p2 - 1; i++){
                    prev2 = prev2->next;
                }

                Node1->next = prev2->next;
                prev2->next = Node1;
                
            }
        }

        void reverse(){

            Node* prev = nullptr;
            Node* curr = head;
            Node* nextnode = nullptr;


            while(curr != nullptr){
                nextnode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextnode;
            }
            
            head = prev;
        }

        void lcyc_shift(int param){
            if(size == 0 || param % size == 0){
                return ; 
            }

            //i know its not matter cause we know that x is smaller than length
            param = param % size;

            Node* curr = head;

            for (int i = 0; i < param - 1; i++){
                curr = curr->next;
            }

            Node* newhead = curr->next;
            curr->next = nullptr;

            Node* tail = newhead;

            while(tail->next != nullptr){
                tail = tail->next;
            }
            
            tail->next = head;
            head = newhead;
        }
       
        void rcyc_shift(int param){
            if (size == 0 || param % size == 0) {
                return;
            }

            param = param % size;

            int shift = size - param;
            lcyc_shift(shift);
        }
};

int main(){
    int choice, param, index; 

    LinkedList mylist;

    while (cin >> choice && choice){
        switch (choice)
        {
        case 1:
            cin >> param >> index;
            mylist.insert_at(param, index);
            break;
        case 2:
            cin >> index;
            mylist.pop_at(index);
            break;
        case 3:
            mylist.display();
            cout << "\n";
            break;
        case 4:
            cin >> param >> index; //param = p1 and index = p2
            mylist.replace(param, index);
            break;
        case 5:
            mylist.reverse();
            break;
        case 6:
            cin >> param;
            mylist.lcyc_shift(param);
            break;
        case 7:
            cin >> param;
            mylist.rcyc_shift(param);
            break;
        
        }
    }


    return 0;
}