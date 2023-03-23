// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
class Solution {
public:
	int search(string pat, string txt) {
	    int ans = 0;
	    int N = txt.size();
	    int M = pat.size();
	    int K = pat.size();
	    std::unordered_map<char, int> freq;
	    for(int i=0; i<M; i++) freq[pat[i]]++;
	    int totalUniqueElement = freq.size();
	    
	    int i = 0;
	    int j = 0;
	    while(i<N && j<N) {
	        // calculation
	        if(freq.find(txt[j]) != freq.end()) {
	            freq[txt[j]]--;
	            if(freq[txt[j]] == 0) totalUniqueElement--;
	        }
	        
	        if(j-i+1 < K) j++;
	        else if(j-i+1 == K) {
	            // ans
	            if(totalUniqueElement == 0) ans++;
	            
    	        // slide
    	        if(freq.find(txt[i]) != freq.end()) {
    	            freq[txt[i]]++;
    	            if(freq[txt[i]] == 1) totalUniqueElement++;
    	        }
    	        i++;
    	        j++;
            }
	    }
	    return ans;
	}
};