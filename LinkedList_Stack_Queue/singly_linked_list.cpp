#include <iostream>

using namespace std;


struct Node{
    
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

};



class LinkedList
{
private:

    Node* head = nullptr;

public:

    void push_front(int value){

        Node* newNode = new Node(value);

        if(head == nullptr){

            head = newNode;

        }else{

            newNode->next = head;
            head = newNode;

        }
    }

    int pop_front(){
        
        int value; Node* temp;

        if(head == nullptr){
            
            cout << "List is empty";
            return -1;

        }else{

            temp = head;
            value = head->data;
            head = head->next;
            delete temp;

            return value;

        }

    }

    void push_back(int value){

        Node* newNode = new Node(value);
        
        if(head == nullptr){ 
             
            head = newNode;

        }else{

        Node* current = head;
        

        while(current->next != nullptr){

            current = current->next;

        }

        current->next = newNode;

        }

    }

    int pop_back(){

        int value; Node* temp;

        if(head == nullptr){

            cout << "List is empty";
            return -1;

        }
        
        if(head->next == nullptr){

            value = head->data;
            delete head;
            head = nullptr;

            return value;

        }

        else{

            Node* current = head;

            while(current->next->next != nullptr){

                current = current->next;

            } 

            value = current->next->data;
            delete current->next;
            current->next = nullptr;

            return value;

        }

    }

    void insert_at(int value, int index){

        int size = list_size();

        if(index > size || index < 0){

            cout << "Index out of range";
            return;

        }

        Node* newNode = new Node(value);
        Node* prev = head; 

        if(index == 0){

            newNode->next = head;
            head = newNode;
            return;

        }

        index--;

        while (index--){

            prev = prev->next;

        }

        newNode->next = prev->next;
        prev->next = newNode;


    }

    int list_size(){

        Node* current = head;
        int size = 0;

        while(current != nullptr){
            
            size++;
            current = current->next;

        }

        return size;

    }

    int pop_at(int index){

        int size = list_size();

        if(size == 0){
            
            cout << "List is empty";
            return -1;

        }

        if(index < 0 || index >= size){

            cout << "Index is out of range";
            return -1;

        }

        int value;

        if(index == 0){

            Node* temp = head;
            value = temp->data;
            head = head->next;
            delete temp;
            return value;

        }

        Node* prev = head; index--;

        while(index--){

            prev = prev->next;

        }

        Node* temp = prev->next;
        value  = temp->data;
        prev->next = temp->next;
        delete temp;
        return value;

    }

    void reverse(){

        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;


        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
            
            head = prev;
        }


    ~LinkedList(){

        while (head != nullptr){

            pop_front();

        }

    }        

};
    
int main(){




    return 0;
}


