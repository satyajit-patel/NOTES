class Node {
    public:
    int data, row, col;

    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class comp {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        std::vector<int> ans;
        int diff = INT_MAX;
        int maxi = INT_MIN;
        std::priority_queue<Node*, std::vector<Node*>, comp> minHeap;
        int k = nums.size();
        for(int i=0; i<k; i++) {
            int element = nums[i][0];
            maxi = std::max( maxi, element);
            minHeap.push(new Node(element, i, 0));
        }
        while(!minHeap.empty()) {
            Node* node = minHeap.top();
            int mini = node->data;
            int row = node->row;
            int col = node->col;
            minHeap.pop();
            int curDiff = maxi-mini;
            if(curDiff < diff) {
                diff = curDiff;
                ans.clear();
                ans.push_back(mini);
                ans.push_back(maxi);
            }
            //check for new element in the same list
            if(col+1 < nums[row].size()) {
                maxi = std::max(maxi , nums[row][col+1]);
                Node* newNode = new Node(nums[row][col+1], row, col+1);
                minHeap.push(newNode);
            }
            else break; // there is no element int the same array
        }
        return ans;
    }
};