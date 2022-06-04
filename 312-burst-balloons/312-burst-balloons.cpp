class Solution {
    int findCoins(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = -1e8;
        for(int itr = i; itr <= j; itr++) {
            int coins = nums[itr]*nums[i-1]*nums[j+1] +
                findCoins(i, itr-1, nums, dp) + findCoins(itr+1, j, nums,dp);
            
            mini = max(coins, mini);
        }
        
        return dp[i][j] = mini;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();    
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        return findCoins(1, n, nums, dp);
    }
};