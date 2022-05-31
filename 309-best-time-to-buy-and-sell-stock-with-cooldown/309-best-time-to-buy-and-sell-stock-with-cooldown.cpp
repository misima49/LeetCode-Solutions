class Solution {
    int findProfit(int ind, bool buy, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        if(ind >= n) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy) {
            return dp[ind][buy] = max(-prices[ind]+findProfit(ind+1, false, prices, dp),
                      findProfit(ind+1, true, prices, dp));
        } else {
            return dp[ind][buy] = max(prices[ind]+findProfit(ind+2, true, prices, dp),
                      findProfit(ind+1, false, prices, dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return findProfit(0, true, prices, dp);
    }
};