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

int findMax(node *root) {
    if(root == NULL) return 0;

    static int maxi = -1;
    findMax(root->left);
    findMax(root->right);
    maxi = max(maxi, root->data);
}
int size(node *root) {
    if(root == NULL) return 0;

    int left = size(root->left);
    int right = size(root->right);
    return left+right+1;
}
void traverse(node *root) {
    if(root == NULL) return;

    cout<<root->data<<" ";
    traverse(root->left);
    traverse(root->right);
    //cout<<root->data<<" "; //post order
}
int height(node *root) {
    if(root == NULL) return 0;

    int l = height(root->left);
    int r = height(root->right);
    return (max(l,r) + 1);
}
int main() {
    root->left = new node(20);                          //10
    root->right = new node(30);                   //20          30
    root->right->left = new node(100);                     //100    (200)
    root->right->right = new node(200);

    cout<<root->right->right->data<<endl; //200
    //delete right's right subtree
    root->right->right = NULL;
    //cout<<root->right->right->data<<endl; //segmentation fault(as we are accessing nothig)

    traverse(root);
    cout<<endl;
    cout<<size(root)<<endl;
    cout<<findMax(root)<<endl;
    cout<<height(root)<<endl;
    return 0;
}