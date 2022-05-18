class Solution {
    bool findSum(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(ind == 0) {
            return (nums[ind] == target);
        }
        
        if(target == 0) return true;
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool notPick = findSum(ind-1, target, nums, dp);
        bool pick = false;
        if(nums[ind] <= target) {
            pick = findSum(ind-1, target-nums[ind], nums, dp);
        }
        
        return dp[ind][target] = pick || notPick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int itr : nums) totalSum += itr;
        if(totalSum % 2 != 0) return false;
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(totalSum/2+1, -1));
        
        return findSum(n-1, totalSum/2, nums, dp);
    }
};