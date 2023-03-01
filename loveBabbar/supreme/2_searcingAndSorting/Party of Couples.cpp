// https://practice.geeksforgeeks.org/problems/alone-in-couple5507/1
class Solution {
public:
    int findSingle(int N, int arr[]){
        std::unordered_map<int, int> M;
        // O(N)
        for(int i=0; i<N; i++) M[arr[i]]++;
        for(auto &it : M) {
            // find the single(odd occurance)
            if(it.second % 2 == 1) return it.first;
        }
        return -1;
    }
};