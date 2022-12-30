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

//delete
//if leaf node----------> delete directly
//if one child node -----> delete the parent and attach the child with grand parent
//if two child node -----> swap with inorder predesasor or successor and place that in recurson eventually that will be deleted
bool isOneChild(node *root) {
    return (root->left == NULL || root->right == NULL); 
}
bool isLeaf(node *root) {
    return (root->left == NULL && root->right == NULL);
}
void deleteOneChild(node *prev, node *p, int target) {
    //attached to grand parent
    if(prev->left && prev->left->data == target) {
        if(p->left) prev->left = p->left; 
        else prev->left = p->right;
    }
    else {
        if(p->left) prev->right = p->left;
        else prev->right = p->right;
    }
}
void deleteLeaf(node *prev, int target) {
    //if left child exist and its the target then delete that
    if(prev->left && prev->left->data == target) prev->left = NULL;
    else prev->right = NULL;
}
node* findInorderSuccessor(node *root) {
    //smallest of right's of tree
    node *p = root->right;
    while(p->left != NULL) { //because we want only small element so we go only left
        p = p->left;
    }
    return p;
}
node* finfInorderPredesasor(node *root) {
    //greatest of left's of tree
    node *p = root->left;
    while(p->right != NULL) {
        p = p->right;
    }
    return p;
}
void del(node *root, int target) {
    node *p = root;
    node *prev = NULL;
    while(p->data != target) {
        prev = p;
        if(target <= p->data) p = p->left;
        else p = p->right;
    }
    if(isLeaf(p)) deleteLeaf(prev, target);
    else if(isOneChild(p)) deleteOneChild(prev, p, target);
    else {
        node *succ = findInorderSuccessor(p);
        swap(succ, p);
        del(p, target);
    }
}

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
    insertRecursive(root, 200);
    traverse(root);
    cout<<endl;

    del(root, 2);
    del(root,20);
    traverse(root);
    cout<<endl;
    return 0;
}