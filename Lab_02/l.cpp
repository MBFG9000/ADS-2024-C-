#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


int findMaxSum(Node* head) {
    if (head == nullptr) return 0;  

    int max_sum = head->data;  
    int current_sum = head->data;  
    
    Node* current = head->next;  

    while (current != nullptr) {
      
        current_sum = max(current->data, current_sum + current->data);

        max_sum = max(max_sum, current_sum);

       
        current = current->next;
    }

    return max_sum;
}


Node* createLinkedList(const int arr[], int n) {
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < n; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

int main() {
    int n;
    cin >> n;  

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

    Node* head = createLinkedList(arr, n);  

    cout << findMaxSum(head) << endl;  

    return 0;
}