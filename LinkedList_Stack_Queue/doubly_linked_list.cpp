#include <iostream>

using namespace std;


struct Node{
    
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

};



class DoublyLinkedList
{
private:

    Node* head = nullptr;
    Node* tail = nullptr;

public:

    void push_back(int value){

        Node* newNode = new Node(value);

        if(tail == nullptr){

            head = tail = newNode;

        }else{

            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;

        }
    }

    void push_front(int value){

        Node* newNode = new Node(value);

        if(head == nullptr){

            head = tail = newNode;

        }else{

            newNode->next = head;
            head->prev = newNode;
            head = newNode;

        }

    }

    void pop_front(){

        if(head == nullptr){
            
            cout << "List is empty";
            return;

        }

        Node* temp = head;

        if(head->next == nullptr){

            head = tail = nullptr;
            
        }else{

            head = head->next;
            head->prev = nullptr;

        }

        delete temp;

    }

    void pop_back(){

        if(tail == nullptr){

            cout << "List is empty";
            return;

        }

        Node* temp = tail;

        if(tail->prev == nullptr){
            
            head = tail = nullptr;

        }else{

            tail = tail->prev;
            tail->next = nullptr;

        }
        
        delete temp;
        
    }

    int front(){

        if(head != nullptr) return head->data; else return -1; 

    }

    int back(){

        if(tail != nullptr) return tail->data; else return -1; 

    }

    ~DoublyLinkedList(){

        while (head != nullptr){

            pop_front();

        }

    }        

};
    



