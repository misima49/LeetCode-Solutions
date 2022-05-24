class Solution {
    int findSubseq(int ind1, int ind2, string text1, string text2, vector<vector<int>>& dp) {
        if(ind1 < 0 || ind2 < 0) 
            return 0;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(text1[ind1] == text2[ind2]) {
            return dp[ind1][ind2] = 1 + findSubseq(ind1-1, ind2-1, text1, text2, dp);
        }
        
        return dp[ind1][ind2] = max(findSubseq(ind1-1, ind2, text1, text2, dp), findSubseq(ind1, ind2-1, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0), cur(m+1, 0);
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1]) {
                    cur[j] = 1+prev[j-1];
                    continue;
                }
                
                cur[j] = max(prev[j], cur[j-1]);
            }
            
            prev = cur;
        }
        
//         for(int i = 0; i <= n; i++) {
//             for(int j = 0; j <= m; j++) {
//                 cout << dp[i][j] << " ";
//             }
            
//             cout << "\n";
//         }
        
        return prev[m];
        
        
        // return findSubseq(n-1, m-1, text1, text2, dp);
    }
};