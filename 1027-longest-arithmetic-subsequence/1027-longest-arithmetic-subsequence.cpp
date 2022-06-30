class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        
        // vector<unordered_map<int, int>> dp(n);
        vector<vector<int>> dp(n, vector<int>(1001, -1));
        int maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 500;
                
                dp[i][diff] = dp[j][diff] == -1 ? 2 : dp[j][diff]+1;
                
                if(maxLen < dp[i][diff]) maxLen = dp[i][diff];
            }
        }
        
        return maxLen;
    }
};