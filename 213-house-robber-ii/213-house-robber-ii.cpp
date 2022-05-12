class Solution {
    int maxProfit(vector<int>& nums, int ind, int end, vector<int>& dp) {
        if(ind < end) {
            return 0;
        }
        if(ind == end) 
            return nums[ind];
        
        if(dp[ind] != -1) return dp[ind];
        
        int pick = nums[ind] + maxProfit(nums, ind-2, end, dp);
        int nonPick = maxProfit(nums, ind-1, end, dp);
        // cout << ind << " " << pick << " " << nonPick << "\n";
        return dp[ind] = max(pick, nonPick);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        vector<int> dp(nums.size(), -1);
        int profitWithFirst = maxProfit(nums, nums.size()-1, 1, dp);
        dp.assign(nums.size(), -1);
        int profitWithLast = maxProfit(nums, nums.size()-2, 0, dp);
        // cout << profitWithFirst << " " << profitWithLast;
        return max(profitWithFirst, profitWithLast);
    }
};