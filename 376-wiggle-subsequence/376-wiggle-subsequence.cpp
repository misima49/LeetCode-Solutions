class Solution {
    int findWiggle(int ind, bool isPrevLarger, vector<int>& nums) {
        int n = nums.size();
        if(ind == n) return 0;
        
        int longestWiggle = 0;
        for(int i = ind+1; i < n; i++) {
            if(isPrevLarger) {
                if(nums[i] > nums[ind]) {
                    longestWiggle = max(longestWiggle, findWiggle(i, false, nums));
                }
            } else {
                if(nums[i] < nums[ind]) {
                    longestWiggle = max(longestWiggle, findWiggle(i, true, nums));
                }
            }
        }
        
        return 1+longestWiggle;
    }
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