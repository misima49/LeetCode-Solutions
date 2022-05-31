class Solution {
    int findProfit(int ind, int transNo, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        if(ind == n || transNo == 0) return 0;
        
        // cout << ind << " " << transNo << "\n";
        if(dp[ind][transNo] != -1) return dp[ind][transNo];
        
        if(transNo % 2 == 0) {
            return dp[ind][transNo] = 
                max(-prices[ind]+findProfit(ind+1, transNo-1, prices, dp),
                      findProfit(ind+1, transNo, prices, dp));
        } else {
            return dp[ind][transNo] = 
                max(prices[ind]+findProfit(ind+1, transNo-1, prices, dp),
                      findProfit(ind+1, transNo, prices, dp));
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2*k+1, -1));
        return findProfit(0, 2*k, prices, dp);
    }
};