class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), 
            count(n, 1);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i] && dp[i] < 1+dp[j]) {
                    dp[i] = 1+dp[j];
                    count[i] = count[j];
                } else if(nums[j] < nums[i] && dp[i] == 1+dp[j]) {
                    count[i] += count[j];
                }
            }
        }
        int LISLen = 0;
        int LISCount = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] > LISLen) {
                LISLen = dp[i];
                LISCount = count[i];
            } else if(dp[i] == LISLen) {
                LISCount += count[i];
            }
        }
        
        // for(int i = 0; i < n; i++) {
        //     cout << nums[i] << " " << dp[i] << " " << count[i] << "\n";
        // }
        
        return LISCount;
    }
};