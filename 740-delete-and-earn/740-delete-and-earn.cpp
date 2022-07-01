class Solution {
    int findPoints(int ind, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if(ind == n) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int notPick = 0, pick = 0;
        int nextPoint;
        for(nextPoint = ind; nextPoint < n && nums[nextPoint] == nums[ind]; nextPoint++);
        
        int curPoints = (nextPoint-ind)*nums[ind];
        notPick = findPoints(nextPoint, nums, dp);
        for(; nextPoint < n && nums[nextPoint] == nums[ind]+1; nextPoint++);
        pick = curPoints + findPoints(nextPoint, nums, dp);
        
        return dp[ind] = max(pick, notPick);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
//         int nex = 0, nex2 = 0;
        
//         for(int i = n-1; i >= 0; i--) {
            
//         }
        
        vector<int> dp(n, -1);
        
        return findPoints(0, nums, dp);
    }
};