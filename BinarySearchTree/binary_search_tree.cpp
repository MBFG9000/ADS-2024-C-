#include <iostream>
#include <vector>

using namespace std;

struct Node{

    int key;
    Node* right;
    Node* left;

    Node(int value){

        this->key = value;
        this->right = this->left = NULL;

    }
    
};

Node* Insert(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
    }
    else if(data <= root->key){
        root->left = Insert(root->left, data);
    }else{
        root->right = Insert(root->right, data);
    }

    return root;
}

Node* MinInRight(Node* current){
    current = current->right;

    while(current != NULL && current->left != NULL){
        current = current->left;
    }

    return current;
}

Node* DeleteNode(Node*& root, int target){
    if(root == NULL){
        return root;
    }

    if(root->key > target){
        root->left = DeleteNode(root->left, target);
    }else if(root->key < target){
        root->right = DeleteNode(root->right, target);
    }

    else{
        
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* successor = MinInRight(root);
        root->key = successor->key;
            root->right = DeleteNode(root->right, successor->key);
    }

    return root;
}

void InOrder(Node* v){
    if(v == NULL){
        return;
    }
    InOrder(v->left);
    cout << v->key << " ";
    InOrder(v->right);
    
}

int main(){

    return 0;
}