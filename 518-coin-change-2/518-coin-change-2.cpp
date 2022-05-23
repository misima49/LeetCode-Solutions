class Solution {
    int findChange(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // cout << ind << " " << amount << "\n";
        if(ind == 0) {
            if(amount == 0 || amount%coins[0] == 0) return 1;
            return 0;
        }
        
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        int notPick = findChange(ind-1, amount, coins, dp);
        int pick = 0;
        if(amount >= coins[ind]) pick = findChange(ind, amount-coins[ind], coins, dp);
        
        return dp[ind][amount] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        dp[0][0] = 1;
        for(int i = coins[0]; i <= amount; i += coins[0]) {
            dp[0][i] = 1;
        }
        
        for(int i = 1; i < n; i++) {
            for(int a = 0; a <= amount; a++) {
                int notPick = dp[i-1][a];
                int pick = 0;
                if(a >= coins[i]) pick = dp[i][a-coins[i]];
                
                dp[i][a] = pick + notPick;
            }
        }
        
        // for(vector<int> itr:dp) {
        //     for(int it:itr) {
        //         cout << it << " ";
        //     }
        //     cout << "\n";
        // }
        
        return dp[n-1][amount];
    }
};