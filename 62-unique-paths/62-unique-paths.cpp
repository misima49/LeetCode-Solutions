class Solution {
    int findPath(int x, int y, vector<vector<int>>& dp) {
        if(x == 0 && y == 0) return 1;
        
        if(dp[x][y] != -1) return dp[x][y];
        
        int left = 0, up = 0;
        if(x > 0) {
            left = findPath(x-1, y, dp);
        }
        
        if(y > 0) {
            up = findPath(x, y-1, dp);
        }
        
        return dp[x][y] = left+up;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findPath(m-1, n-1, dp);
    }
};