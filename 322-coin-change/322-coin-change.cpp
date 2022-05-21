class Solution {
    int findChange(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // if(amount == 0) return 1;
        if(ind == 0) {
            if(amount%coins[ind] == 0) return amount/coins[ind];
            else return 1e8;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        int notPick = findChange(ind-1, amount, coins, dp);
        int pick = 1e8;
        if(coins[ind] <= amount) pick = 1 + findChange(ind, amount-coins[ind], coins, dp);
        
        return dp[ind][amount] = min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int answer = findChange(n-1, amount, coins, dp);
        
        
        if(answer == 1e8) return -1;
        return answer;
    }
};