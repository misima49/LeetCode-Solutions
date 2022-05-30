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
        vector<vector<int>> next(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));
        
        for(int ind = n-1; ind >= 0; ind--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= 2; cap++) {
                    // cout << ind << " " << buy << " " << cap << "\n";
                    int profit = 0;
                    if(buy) {
                        profit = max(-prices[ind] + next[!buy][cap],
                                     next[buy][cap]);
                    } else {
                        profit = max(prices[ind] + next[!buy][cap-1],
                                    next[buy][cap]);
                    }

                    cur[buy][cap] = profit;
                }
                
                next = cur;
            }
        }
        
        return next[1][2];
        // return findProfit(0, true, 2, prices, dp);
    }
};