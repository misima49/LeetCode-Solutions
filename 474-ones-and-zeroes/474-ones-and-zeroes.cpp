class Solution {
    int find01(int ind, int m, int n, vector<string>& strs, vector<vector<vector<int>>>& dp) {
        if(ind == 0) {
            if(count(strs[0].begin(), strs[0].end(), '0') <= m && count(strs[0].begin(), strs[0].end(), '1') <= n) {
                return 1;
            }
            
            return 0;
        }
        
        
        if(dp[ind][m][n] != -1) return dp[ind][m][n];
        
        int notPick = find01(ind-1, m, n, strs, dp);
        int pick = INT_MIN;
        
        int zeroes = count(strs[ind].begin(), strs[ind].end(), '0');
        int ones = count(strs[ind].begin(), strs[ind].end(), '1');
        
        if(zeroes <= m && ones <= n) pick = 1+find01(ind-1, m-zeroes, n-ones, strs, dp);
        
        return dp[ind][m][n] = max(pick, notPick);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return find01(len-1, m, n, strs, dp);
    }
};