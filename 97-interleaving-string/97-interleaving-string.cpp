class Solution {
    bool findIfPossible(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp) {
        if(i == s1.length() && j == s2.length()) return true;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        dp[i][j] = false;
        // cout << s1[i] << " " << s2[j] << " " << s3[i+j] << "\n";
        if(s1[i] == s3[i+j] && findIfPossible(i+1, j, s1, s2, s3, dp)) return dp[i][j] = true;
        if(s2[j] == s3[i+j] && findIfPossible(i, j+1, s1, s2, s3, dp)) return dp[i][j] = true;
        
        return dp[i][j];
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length();
        
        if(l1+l2 != s3.length()) return false;
        
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, -1));
        return findIfPossible(0, 0, s1, s2, s3, dp);
    }
};