
/*
struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */
class Solution {
public:
    void f(Node* root, int sum, int& maxSum, int len, int& maxLen) {
        // base case
        if(!root) return;
        if(!root->left && !root->right) {
            // 1 case pre work
            sum += root->data;
            if(len > maxLen) {
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen) maxSum = std::max(maxSum, sum);
            return;
        }
        
        // 1 case pre work
        sum += root->data;
        // recursive case
        f(root->left, sum, maxSum, len+1, maxLen);
        f(root->right, sum, maxSum, len+1, maxLen);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        int sum = 0, maxSum = 0, len = 0, maxLen = 0;
        f(root, sum, maxSum, len, maxLen);
        return maxSum;
    }
};