class Solution {
    bool partition(int ind, vector<int>& nums, vector<int>& dp) {
        // cout << ind << " ";
        int n = nums.size();
       
        if(ind == n-1) return false;
        if(ind == n-2) return nums[ind] == nums[ind+1];
        else if(ind > n-1) return true;
        
        if(dp[ind] != -1) return dp[ind];
        // cout << nums[ind] << nums[ind+1] << nums[ind+2] << '\n';
        
        int par = false;
        if(nums[ind] == nums[ind+1]) par |= partition(ind+2,nums, dp);
        if(nums[ind] == nums[ind+1] && nums[ind+1] == nums[ind+2]) par |= partition(ind+3, nums, dp);
        if(nums[ind]+1 == nums[ind+1] && nums[ind+1] == nums[ind+2]-1) par |= partition(ind+3, nums, dp);
        
        return dp[ind] = par;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return partition(0, nums, dp);
    }
};