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



class Queue
{
private:

    Node* head = nullptr;
    Node* tail = nullptr;

public:

    void push(int value){

        Node* newNode = new Node(value);

        if(tail == nullptr){

            head = tail = newNode;

        }else{

            tail->next = newNode;
            tail = newNode;

        }
    }

    int pop(){

        if(head == nullptr){

            cout << "Queue is empty";
            return -1;

        }

        int value = head->data;
        Node* temp = head;
        head = head->next;

        if(head == nullptr){

            tail = nullptr;
            
        }

        delete temp;
        return value;

    }

    ~Queue(){

        while (head != nullptr){

            pop();

        }

    }        

};
    
int main(){




    return 0;
}


