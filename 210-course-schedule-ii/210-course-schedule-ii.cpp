class Solution {
    vector<int> topoSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> indeg(n, 0);
        
        for(vector<int> itr : adj) {
            for(int i : itr) {
                indeg[i]++;
            }
        }
        vector<int> topo;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) 
                q.push(i);
        }
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            topo.push_back(cur);
            for(int itr : adj[cur]) {
                indeg[itr]--;
                if(indeg[itr] == 0)
                    q.push(itr);
            }
        }
        
        if(topo.size() != n) return {};
        
        return topo;
        
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(vector<int> itr : prerequisites) {
            adj[itr[1]].push_back(itr[0]);
        }
        
        return topoSort(adj);
    }
};