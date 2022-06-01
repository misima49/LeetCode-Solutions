class Solution {
    int findLIS(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if(ind == n) return 0;
        
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        
        int notPick = findLIS(ind+1, prev, nums, dp);
        int pick = -1e8;
        if(prev == -1 || nums[prev] < nums[ind]) pick = 1 + findLIS(ind+1, ind, nums, dp);

        // return max(pick, notPick);
        // cout << ind << " " << prev << "\n";
        return dp[ind][prev+1] = max(pick, notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return findLIS(0, -1, nums, dp);
    }
};