class Solution {
    bool isPossible(unordered_map<int, unordered_set<int>>& adj, vector<int>& flowerType, int n, int curr) {
        if(curr == n+1) return true;
        
        bool flag = false;
        for(int i = 1; i <= 4; i++) {
            flag = false;
            for(int itr:adj[curr]) {
                if(flowerType[itr-1] == i) {
                    flag = true;
                    break;
                }
            }
            
            if(flag == true) continue;
            
            flowerType[curr-1] = i;
            if(isPossible(adj, flowerType, n, curr+1)) return true;
            flowerType[curr-1] = -1;
        }
        
        return false;
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int, unordered_set<int>> adj;
        for(int i = 0; i < paths.size(); i++) {
            adj[paths[i][0]].insert(paths[i][1]);
            adj[paths[i][1]].insert(paths[i][0]);
        }
        
        vector<int> flowerType(n, -1);
        isPossible(adj, flowerType, n, 1);

        return flowerType;
    }
};