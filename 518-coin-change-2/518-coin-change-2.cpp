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
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return findChange(n-1, amount, coins, dp);
    }
};