class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        
        for(vector<int> itr : edges) {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
            deg[itr[0]]++;
            deg[itr[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(deg[i] == 1)
                q.emplace(i);
        }
        
        vector<int> res;
        while(!q.empty()) {
            res.clear();
            int sz = q.size();
            
            while(sz--) {
                for(int i : adj[q.front()]) {
                    deg[i]--;
                    if(deg[i] == 1)
                        q.emplace(i);
                }
                res.push_back(q.front());
                q.pop();
            }
        }
        
        return res;
    }
};