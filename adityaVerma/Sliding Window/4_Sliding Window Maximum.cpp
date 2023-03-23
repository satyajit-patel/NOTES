// https://www.interviewbit.com/problems/sliding-window-maximum/
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    std::vector<int> ans;
    std::deque<int> temp;
    int N = A.size();
    
    // int i = 0;
    // int j = 0;
    // while(i<N && j<N) {
    //     // calculation
    //     temp.push_back(A[j]);
        
    //     if(j-i+1 < B) j++;
    //     else if(j-i+1 == B) {
    //         // ans
    //         int maxi = *std::max_element(temp.begin(), temp.end()); // TLE
    //         ans.push_back(maxi);
            
    //         // slide
    //         temp.pop_front();
    //         i++;
    //         j++;
    //     }
    // }
    
    // // works fine
    // int maxi = INT_MIN; 
    // int i = 0;
    // int j = 0;
    // while(i<N && j<N) {
    //     // calculation
    //     temp.push_back(A[j]);
    //     maxi = std::max(maxi, A[j]);
        
    //     if(j-i+1 < B) j++;
    //     else if(j-i+1 == B) {
    //         // ans
    //         ans.push_back(maxi);
            
    //         // slide
    //         if(A[i] != maxi) temp.pop_front();
    //         else {
    //             temp.pop_front();
    //             if(!temp.empty()) maxi = *std::max_element(temp.begin(), temp.end());
    //             else maxi = INT_MIN;
    //         }
    //         i++;
    //         j++;
    //     }
    // }
    

    int i = 0;
    int j = 0;
    while(i<N && j<N) {
        // calculation
        while(!temp.empty() && A[j]>temp.back()) temp.pop_back();
        temp.push_back(A[j]);
        
        if(j-i+1 < B) j++;
        else if(j-i+1 == B) {
            // ans
            ans.push_back(temp.front());
            
            // slide
            if(A[i] == temp.front()) temp.pop_front();
            i++;
            j++;
        }
    }
    return ans; 
}
