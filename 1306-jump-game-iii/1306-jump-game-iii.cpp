class Solution {
private:
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& arr, vector<bool>& visited) {
        visited[i] = true;
        if(arr[i] == 0) return true;
        for(int itr : adj[i]) {
            if(!visited[itr] && dfs(itr, adj, arr, visited)) return true;
        }
        
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < n; i++) {
            if(i+arr[i] < n)
                adj[i].push_back(i+arr[i]);
            if(i-arr[i] >= 0) 
                adj[i].push_back(i-arr[i]);
        }
        vector<bool> visited(n, false);
        return dfs(start, adj, arr, visited);
    }
};