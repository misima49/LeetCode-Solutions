class Solution {
    int findMoney(int ind, bool canRob, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if(ind == n) return 0;
        
        if(dp[ind][canRob] != -1) return dp[ind][canRob];
        
        int pick = 0;
        int notPick = 0;
        if(canRob) {
            pick = nums[ind] + findMoney(ind+1, !canRob, nums, dp);
            notPick = findMoney(ind+1, canRob, nums, dp);
        } else {
            notPick = findMoney(ind+1, !canRob, nums, dp);
        }
        // cout << pick << "\n";
        return dp[ind][canRob] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        
        for(int i = n-1; i >= 0; i--) {
            int pick = 0;
            int notPick = 0;
            pick = nums[i] + dp[i+1][false];
            notPick = dp[i+1][true];
            
            dp[i][true] = max(pick, notPick);
            dp[i][false] = notPick;
            
        }
        
        return dp[0][true];
        // return findMoney(0, true, nums, dp);
    }
};