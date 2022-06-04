class Solution {
    int findCost(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e8;
        for(int itr = i; itr <= j; itr++) {
            int cost = cuts[j+1] - cuts[i-1] + findCost(i, itr-1, cuts, dp) + findCost(itr+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int len = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(len+1, vector<int>(len+1, -1));
        
        return findCost(1, len, cuts, dp);
    }
};