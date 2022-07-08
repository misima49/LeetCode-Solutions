class Solution {
    int findCost(int ind, vector<int>& houses, vector<vector<int>>& cost,
                int m, int n, int target, vector<vector<vector<int>>>& dp) {
        
        if(ind == m) {
            if(target == 0) return 0;
            return 1e8;
        } else if(target < 0) 
            return 1e8;
        
        if(dp[ind][ind > 0 ? houses[ind-1] : 0][target] != -1) return dp[ind][ind > 0 ? houses[ind-1] : 0][target];
        
        int mini = 1e8;
        
        if(houses[ind] == 0) {
            for(int i = 1; i <= n; i++) {
                houses[ind] = i;
                if(ind > 0 && houses[ind-1] == i) {
                    mini = min(mini, findCost(ind+1, houses, cost, m, n, target, dp) + cost[ind][i-1]);
                } else {
                    mini = min(mini, findCost(ind+1, houses, cost, m, n, target-1, dp) + cost[ind][i-1]);
                    
                }
                
                houses[ind] = 0;
            }
        } else {
            if(ind == 0 || houses[ind-1] != houses[ind]) {
                mini = min(mini, findCost(ind+1, houses, cost, m, n, target-1, dp));
            } else {
                mini = min(mini, findCost(ind+1, houses, cost, m, n, target, dp));
            }
        }
        
        return dp[ind][ind > 0 ? houses[ind-1] : 0][target] = mini;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n+1, vector<int>(target+1, -1)));
        int c = findCost(0, houses, cost, m, n, target, dp);
        if(c == 1e8) return -1;
        return c;
    }
};