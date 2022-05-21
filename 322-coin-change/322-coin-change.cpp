class Solution {
//     int findChange(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
//         if(ind == 0) {
//             if(amount%coins[ind] == 0) return amount/coins[ind];
//             else return 1e8;
//         }
//         if(dp[ind][amount] != -1) return dp[ind][amount];
        
//         int notPick = findChange(ind-1, amount, coins, dp);
//         int pick = 1e8;
//         if(coins[ind] <= amount) pick = 1 + findChange(ind, amount-coins[ind], coins, dp);
        
//         return dp[ind][amount] = min(pick, notPick);
//     }
public:
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 1e8));
        
        for(int i = 0; i <= target; i++) {
            if(i%coins[0] == 0) {
                dp[0][i] = i/coins[0];
            }
        }
        // cout << "here1\n";
        for(int i = 1; i < n; i++) {
            // cout << "here4\n";
            for(int j = 0; j <= target; j++) {
                // cout << "here3\n";
                int notPick = dp[i-1][j];
                int pick = 1e8;
                if(coins[i] <= j) pick = 1 + dp[i][j-coins[i]];
                
                dp[i][j] = min(pick, notPick);
            }
        }
        // cout << "here2\n";
        // int answer = findChange(n-1, amount, coins, dp);
        
        if(dp[n-1][target] == 1e8) return -1;
        return dp[n-1][target];
        // return answer;
    }
};