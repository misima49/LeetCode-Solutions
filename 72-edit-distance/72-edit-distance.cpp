class Solution {
    int findDistance(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if(j < 0) return i+1;
        if(i < 0) return j+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = findDistance(i-1, j-1, s1, s2, dp);
        
        int ins = 1+findDistance(i, j-1, s1, s2, dp);
        int del = 1+findDistance(i-1, j, s1, s2, dp);
        int rep = 1+findDistance(i-1, j-1, s1, s2, dp);
        
        return dp[i][j] = min({ins, del, rep});
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<int> prev(n+1, 0), cur(n+1, 0);
        
        for(int j = 0; j <= n; j++) {
            prev[j] = j;
        }
        
        for(int i = 1; i <= m; i++) {
            cur[0] = i;
            for(int j = 1; j <= n; j++) {
                if(word1[i-1] == word2[j-1])
                    cur[j] = prev[j-1];
                else {
                    int ins = 1+cur[j-1];
                    int del = 1+prev[j];
                    int rep = 1+prev[j-1];
                    
                    cur[j] = min({ins, del, rep});
                }
            }
            prev = cur;
        }
        
        return prev[n];
    }
};