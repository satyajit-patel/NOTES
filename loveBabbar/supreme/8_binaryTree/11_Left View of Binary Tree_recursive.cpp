/*
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
void f(Node* root, int level, std::vector<int>& leftView) {
    // base case
    if(!root) return;
    
    // 1 case pre work
    if(level == leftView.size()) leftView.push_back(root->data);
    
    // recursive case
    f(root->left, level+1, leftView);
    f(root->right, level+1, leftView);
}

vector<int> leftView(Node *root) {
    std::vector<int> leftView;
    f(root, 0, leftView);
    return leftView;
}