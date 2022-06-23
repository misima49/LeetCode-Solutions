class Solution {
    void dfs(int i, vector<bool>& visited, vector<vector<int>>& adj, int& ans) {
        visited[i] = true;
        
        for(int itr : adj[i]) {
            if(!visited[abs(itr)]) {
                if(itr < 0 ) {
                    ans++;
                }
                dfs(abs(itr), visited, adj, ans);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(vector<int> itr : connections) {
            adj[itr[1]].push_back(itr[0]);
            adj[itr[0]].push_back(-itr[1]);
        }
        int ans = 0;
        vector<bool> visited(n, false);
        dfs(0, visited, adj, ans);
        
        return ans;
    }
};