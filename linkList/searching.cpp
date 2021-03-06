#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;   // next pointer points to whole node

        // Constructor
        node(int d) {
            data = d;
            next = NULL; // Initially next pointer is NULL 
        }
};
void insertAtHead (node* &head, int data){
    node*n = new node(data);
    n->next = head;
    head = n;
}
void print(node*head) {
    node*temp = head;
    while(temp!=NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}
bool searchRecursive(node* &head, int key){
    if(head == NULL) {
        return false;
    }
    else if(head->data == key){
        return true;
    }
    else {
        return searchRecursive(head->next, key);
    }
}
bool searchLiner(node* &head, int key){
    while(head!=NULL){
        if(head->data == key){
            return true;
        }
        head = head->next;
    }
    return false;
}

int main() {
    node* head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    if(searchRecursive(head, 4)){
        cout << "Element is Present";
    }
    else {
        cout << "Not present";
    }
    if(searchLiner(head, 7)){
        cout << "Element is present";
    }
    else {
        cout << "Not present";
    }
    return 0;
}