/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node *left, *right;
};
*/

// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
bool f(int& res, Node* root, int& k, int p) {
    // base case
    if(root == NULL) return false;
    if(root->data == p) return true;
    
    // recursive case
    bool leftAns = f(res, root->left, k, p);
    bool rightAns = f(res, root->right, k, p);
    
    // calculate and return while coming back
    if(leftAns == true || rightAns == true) k--;
    if(k == 0) {
        res = root->data;
        k = -1; // just making sure we don't encounter zero again
    }
    bool ans = leftAns || rightAns;
    return ans;
}

int kthAncestor(Node *root, int k, int node) {
    int res = -1;
    f(res, root, k, node);
    return res;
}
