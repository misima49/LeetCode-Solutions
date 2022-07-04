class Solution {
    bool bfsBipartite(int sc, vector<vector<int>>& adj, vector<bool>& visited) {
        vector<int> color(adj.size(), -1);
        visited[sc] = true;
        color[sc] = 1;
        queue<int> q;
        q.emplace(sc);
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for(int itr : adj[cur]) {
                if(!visited[itr]) {
                    q.emplace(itr);
                    visited[itr] = true;
                    color[itr] = 1-color[cur];
                } else if(color[itr] == color[cur]) {
                    return false;
                }
            }
        }
        
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        
        for(vector<int> itr : dislikes) {
            adj[itr[0]].push_back(itr[1]);
        }
        
        vector<bool> visited(n, false);
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && !bfsBipartite(i, adj, visited)) return false;
        }
        
        return true;
    }
};