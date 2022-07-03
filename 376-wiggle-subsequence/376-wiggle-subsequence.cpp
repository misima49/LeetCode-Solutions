class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if(nums[j] > nums[i]) {
                    dp[i][0] = max(dp[i][0], dp[j][1]);
                } else if(nums[j] < nums[i]) {
                    dp[i][1] = max(dp[i][1], dp[j][0]);
                }
            }
            dp[i][0]++;
            dp[i][1]++;
        }
        
        return max(dp[0][0], dp[0][1]);
    }
};