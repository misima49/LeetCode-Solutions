class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n+1, 0);
        
        for(int i = n-1; i >= 0; i--) {
            int nexPoint = i;
            
            while(nexPoint < n && nums[nexPoint] == nums[i]) nexPoint++;
            int points = (nexPoint-i)*nums[i];
            int notPick = dp[nexPoint];
            
            while(nexPoint < n && nums[nexPoint] == nums[i]+1) nexPoint++;
            int pick = points + dp[nexPoint];
            
            dp[i] = max(pick, notPick);
        }
        
        return dp[0];
    }
};