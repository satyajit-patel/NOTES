// https://practice.geeksforgeeks.org/contest/upcoming-sde-contest-1/problems#
class Solution{   
private:
    // Explanation:
    // A[][] =[[0,1,1],
    //         [1,1,1],
    //         [0,0,1]]
    // Row with index 1 has maximum number of 1s. 
    
    // do not edit this function
    // use it to get the value of A[i][j]
    int get(int i,int j){
        return a.get(i,j);
    }
public:
    int solve(int R,int C){
        int ans = 0;
        int j = C - 1;
        for(int i=0; i<R; i++) {
            while(j>=0 && a.get(i, j)==1) {
                j--;
                ans = i;
            }
        }
        return ans;
    }
};