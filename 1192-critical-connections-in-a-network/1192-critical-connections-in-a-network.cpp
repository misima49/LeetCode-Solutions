class Solution {
    vector<vector<int>> ans;
    
    void findCritConnec(int sc, int parent, vector<vector<int>>& adj, vector<int>& visitTime, vector<int>& lowTime, int time) {
        lowTime[sc] = visitTime[sc] = time++;
        
        for(int itr : adj[sc]) {
            if(itr == parent) continue;
            
            if(visitTime[itr] == -1) {
                findCritConnec(itr, sc, adj, visitTime, lowTime, time);
                lowTime[sc] = min(lowTime[sc], lowTime[itr]);
                // cout << lowTime[itr] << " " << visitTime[sc] << "\n";
                if(lowTime[itr] > visitTime[sc]) {
                    ans.push_back({itr, sc});
                }
            } else {
                lowTime[sc] = min(lowTime[sc], visitTime[itr]);
            }
        }
        
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(vector<int> itr : connections) {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        
        int time = 0;
        vector<int> visitTime(n, -1);
        vector<int> lowTime(n, 0);
        
        findCritConnec(0, -1, adj, visitTime, lowTime, time);
        
        return ans;
    }
};