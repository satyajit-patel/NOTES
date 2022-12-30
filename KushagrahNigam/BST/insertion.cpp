#include<iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *root = new node(10);

void traverse(node *root) {
    if(root == NULL) return;

    traverse(root->left);
    cout<<root->data<<" ";  //inorder traversal of BST is always in increasing oreder
    traverse(root->right);
}
void insertIterative(node *root, int x) {
    node *prev = NULL;
    while(root != NULL) {
        prev = root;
        if(x <= root->data) root = root->left;
        else root = root->right;
    }
    if(x < prev->data) prev->left = new node(x);
    else prev->right = new node(x);
}
node* insertRecursive(node *root, int x) {
    if(root == NULL) return root  = new node(x);

    if(x <= root->data) root->left = insertRecursive(root->left, x);
    else root->right = insertRecursive(root->right, x);
}
int main() {
    insertIterative(root, 5);
    insertIterative(root, 20);
    insertRecursive(root, 2);
    insertRecursive(root, 100);
    traverse(root);
    return 0;
}