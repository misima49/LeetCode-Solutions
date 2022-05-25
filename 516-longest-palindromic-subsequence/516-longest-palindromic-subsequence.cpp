class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int len = s1.length();
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        
        vector<vector<int>> dp(len+1, vector<int>(len+1, 0));
        
        for(int i = 1; i <= len; i++) {
            for(int j = 1; j <= len; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        return dp[len][len];
    }
};