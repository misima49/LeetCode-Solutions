class Solution {
    int findProfit(int ind, bool buy, int cap, vector<int>& prices,
                  vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        if(cap == 0) return 0;
        if(ind == n) return 0;
        
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        int profit = 0;
        if(buy) {
            profit = max(-prices[ind]+findProfit(ind+1, false, cap, prices, dp),
                         findProfit(ind+1, true, cap, prices, dp));
        } else {
            profit = max(prices[ind]+findProfit(ind+1, true, cap-1, prices, dp),
                        findProfit(ind+1, false, cap, prices, dp));
        }
        
        return dp[ind][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        
        return findProfit(0, true, 2, prices, dp);
    }
};