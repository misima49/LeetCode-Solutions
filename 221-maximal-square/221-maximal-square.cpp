class Solution {
    int ans;
    int findSq(int r, int c, vector<vector<char>>& matrix, vector<vector<int>>& dp) {
        if(r < 0 || c < 0) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        
        if(matrix[r][c] == '1') {
            int diag = min({findSq(r-1, c-1, matrix, dp), findSq(r-1, c, matrix, dp), findSq(r, c-1, matrix, dp)}) + 1;
            ans = max(ans, diag);
            return dp[r][c] = diag;
        } else {
            findSq(r-1, c, matrix, dp);
            findSq(r, c-1, matrix, dp);
            return dp[r][c] = 0;
        }
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int diag = findSq(n-1, m-1, matrix, dp);
        
        return ans*ans;
    }
};