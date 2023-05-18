/*
struct Node {
    int data;
    Node* left, * right;
}; */

// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }
    
    void leftBoundary(Node* root, std::vector<int>& boundaryView) {
        // base case
        if(!root) return;
        if(isLeaf(root)) return;
        
        // 1 case pre work
        boundaryView.push_back(root->data);
        
        // recursive case
        if(root->left) leftBoundary(root->left, boundaryView);
        else leftBoundary(root->right, boundaryView); // only call if riquired
    }
    
    void leafBoundary(Node* root, std::vector<int>& boundaryView) {
        // base case
        if(!root) return;
        
        // 1 case pre work
        if(isLeaf(root)) boundaryView.push_back(root->data);
        
        // recursive case
        leafBoundary(root->left, boundaryView);
        leafBoundary(root->right, boundaryView);
    }
    
    void rightBoundary(Node* root, std::vector<int>& boundaryView) {
        // base case 
        if(!root) return;
        if(isLeaf(root)) return;
        
        // recursive case
        if(root->right) rightBoundary(root->right, boundaryView);
        else rightBoundary(root->left, boundaryView); // only call if riquired
    
        // 1 case post work
        boundaryView.push_back(root->data);
    }
    
    vector<int> boundary(Node *root) {
        std::vector<int> boundaryView;
        if(!root) boundaryView;
        boundaryView.push_back(root->data);
        if(isLeaf(root)) return boundaryView;
        
        leftBoundary(root->left, boundaryView);
        leafBoundary(root, boundaryView);
        rightBoundary(root->right, boundaryView);
        
        return boundaryView;
    }
};