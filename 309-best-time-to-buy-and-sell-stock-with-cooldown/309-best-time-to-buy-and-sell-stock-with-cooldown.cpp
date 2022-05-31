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
        // vector<vector<int>> dp(n+2, vector<int>(2, 0));
        
        vector<int> next2(2, 0), next(2, 0), cur(2, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                if(buy) {
                    cur[buy] = max(-prices[i]+next[false],
                                    next[true]);
                } else {
                    cur[buy] = max(prices[i]+next2[true],
                                    next[false]);
                }
            }
            
            next2 = next;
            next = cur;
        }
        
        
        return cur[true];
        // return findProfit(0, true, prices, dp);
    }
};