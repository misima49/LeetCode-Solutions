class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int itr : nums) target += itr;
        if(target % 2 != 0) return false;
        target /= 2;
        int n = nums.size();
        
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        
        if(nums[0] <= target)
            dp[0][nums[0]] = true;
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= target; j++) {
                bool notPick = dp[i-1][j];
                bool pick = false;
                if(nums[i] < j) pick = dp[i-1][j-nums[i]];
                
                dp[i][j] = pick || notPick;
            }
        }
        return dp[n-1][target];
    }
};