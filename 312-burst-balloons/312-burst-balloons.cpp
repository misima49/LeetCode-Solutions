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
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        for(int i = n; i >= 1; i--) {
            for(int j = 1; j <= n; j++) {
                if(i > j) continue;
                
                int maxi = -1e8;
                for(int itr = i; itr <= j; itr++) {
                    int cost = nums[i-1]*nums[itr]*nums[j+1] +
                        dp[i][itr-1] + dp[itr+1][j];
                    
                    maxi = max(cost, maxi);
                }
                
                dp[i][j] = maxi;
            }
        }
        
        // return findCoins(1, n, nums, dp);
        return dp[1][n];
    }
};