// https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary
class Solution {
public:
    void dfs(int root, std::vector<int> adj[], std::vector<int>& vis, std::stack<int>& st) {
        vis[root] = 1;
        for(auto &child : adj[root]) {
            if(!vis[child]) dfs(child, adj, vis, st);
        }
        st.push(root);
    }

    string findOrder(string dict[], int N, int K) {
        std::vector<int> adj[K];
        for(int i=0; i<N-1; i++) {
            std::string s1 = dict[i];
            std::string s2 = dict[i+1];
            int len = std::min(s1.size(), s2.size());
            for(int x=0; x<len; x++) {
                if(s1[x] != s2[x]) {
                    int u = s1[x] - 'a';
                    int v = s2[x] - 'a';
                    adj[u].push_back(v);
                    break;
                }
            }
        }
        std::vector<int> vis(K, 0);
        std::stack<int> st;
        for(int i=0; i<K; i++) {
            if(!vis[i]) dfs(i, adj, vis, st);
        }
        std::vector<int> toposort;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            toposort.push_back(node);
        }
        std::string ans = "";
        for(auto &it : toposort) ans += (char)(it + 'a');
        return ans;
    }
};