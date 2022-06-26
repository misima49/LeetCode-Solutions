class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adj(n);
        
        for(vector<int> itr : roads) {
            adj[itr[0]].insert(itr[1]);
            adj[itr[1]].insert(itr[0]);
        }
        
        int maxRank = 0;
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                // cout << i << " " << j << "\n";
                int pairRank = adj[i].size() + adj[j].size();
                if(adj[i].count(j)) pairRank--;
                
                if(maxRank < pairRank) maxRank = pairRank;
            }
        }
        
        return maxRank;
    }
};