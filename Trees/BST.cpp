#include <iostream>
#include <queue>
using namespace std;
// BUILDING A BST
class node {
public:
    int data;
    node* left;
    node* right;

    // constructor
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
node* insertAtBST(node*root, int data){
    if(root == NULL){
        return new node(data);
    }
    if(data <= root->data){
       root->left = insertAtBST(root->left, data);
    }
    else {
       root->right = insertAtBST(root->right, data);
    }
    return root;
}
node* build(){
    int d;
    cin >> d;
    node*root = NULL;
    while(d != -1){
        root = insertAtBST(root, d);
        cin >> d;
    }
    return root;
}
void BFS(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f = q.front();
        if(f == NULL){
            cout << endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout << f->data << " ";
        q.pop();

        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
        }
    }
    return;
}
void inorder(node*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << ",";
    inorder(root->right);
}
int main () {
    node*root = build();
    inorder(root);
    cout << endl;
    BFS(root);
    return 0;
}
