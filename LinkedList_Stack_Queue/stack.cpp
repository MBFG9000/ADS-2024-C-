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



class Stack
{
private:

    Node* head = nullptr;

public:

    void push(int value){

        Node* newNode = new Node(value);

        if(head == nullptr){

            head = newNode;

        }else{

            newNode->next = head;
            head = newNode;

        }
    }

    void pop(){
        
        Node* temp;

        if(head == nullptr){
            
            cout << "Stack is empty";
            return;

        }else{

            temp = head;
            head = head->next;
            delete temp;

        }

    }

    int top(){
        if(head == nullptr){

            cout << "Stack is empty";
            return -1;

        }

        return head->data;

    }

    ~Stack(){

        while (head != nullptr){

            pop();

        }

    }        

};
    


