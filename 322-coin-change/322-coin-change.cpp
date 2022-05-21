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
        vector<int> prev(target+1, 0), cur(target+1, 0);
        
        for(int i = 0; i <= target; i++) {
            if(i%coins[0] == 0) {
                prev[i] = i/coins[0];
            } else {
                prev[i] = 1e8;
            }
        }
       
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= target; j++) {
                int notPick = prev[j];
                int pick = 1e8;
                
                if(coins[i] <= j) pick = 1 + cur[j-coins[i]];
                
                cur[j] = min(pick, notPick);
            }
           
            prev = cur;
        }
        
        if(prev[target] == 1e8) return -1;
        return prev[target];
    }
};