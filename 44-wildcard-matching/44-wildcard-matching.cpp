class Solution {
    bool findMatch(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if(i < 0 && j < 0) return true;
        if(i < 0) {
            for(int itr = j; itr >= 0; itr--) {
                if(p[itr] != '*') return false;
            }
            
            return true;
        }
        if(i >= 0 && j < 0) return false;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = findMatch(i-1, j-1, s, p, dp);
        else if(p[j] == '*') {
            int zeroLen = findMatch(i, j-1, s, p, dp);
            int someLen = findMatch(i-1, j, s, p, dp);
            return dp[i][j] = zeroLen || someLen;
        } else {
            return dp[i][j] = 0;
        }
    }
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return findMatch(n-1, m-1, s, p, dp);
    }
};