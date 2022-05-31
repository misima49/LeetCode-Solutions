class Solution {
//     int findProfit(int ind, int transNo, vector<int>& prices, vector<vector<int>>& dp) {
//         int n = prices.size();
//         if(ind == n || transNo == 0) return 0;
        
//         // cout << ind << " " << transNo << "\n";
//         if(dp[ind][transNo] != -1) return dp[ind][transNo];
        
//         if(transNo % 2 == 0) {
//             return dp[ind][transNo] = 
//                 max(-prices[ind]+findProfit(ind+1, transNo-1, prices, dp),
//                       findProfit(ind+1, transNo, prices, dp));
//         } else {
//             return dp[ind][transNo] = 
//                 max(prices[ind]+findProfit(ind+1, transNo-1, prices, dp),
//                       findProfit(ind+1, transNo, prices, dp));
//         }
//     }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        
        for(int i = n-1; i >= 0; i--) {
            for(int transNo = 1; transNo <= 2*k; transNo++) {
                if(transNo % 2 == 0) {
                    dp[i][transNo] = 
                        max(-prices[i]+dp[i+1][transNo-1], 
                            dp[i+1][transNo]);
                } else {
                    dp[i][transNo] = 
                        max(prices[i]+dp[i+1][transNo-1],
                           dp[i+1][transNo]);
                }
            }
        }
        
        return dp[0][2*k];
        // return findProfit(0, 2*k, prices, dp);
    }
};