

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
};
*/

// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

#define vi std::vector<int>
class Solution {
public:
    int maxi, ans;
    void f(Node* root, int& sum, vi& path) {
        // base case
        if(!root) return;
        if(!root->left && !root->right) {
            // 1 case pre work
            sum += root->data;
            path.push_back(root->data);
            
            int N = path.size();
            if(N == maxi) ans = std::max(ans, sum);
            else if(N > maxi) {
                maxi = N;
                ans = sum;
            }
            
            // backtrack
            sum -= root->data;
            path.pop_back();
            
            return;
        }
        
        // 1 case pre work
        sum += root->data;
        path.push_back(root->data);
        
        // recursive case
        f(root->left, sum, path);
        f(root->right, sum, path);
        
        // backtrack
        sum -= root->data;
        path.pop_back();
    }

    int sumOfLongRootToLeafPath(Node *root) {
        maxi = 0, ans = 0;
        int sum = 0;
        vi path;
        f(root, sum, path);
        return ans;
    }
};