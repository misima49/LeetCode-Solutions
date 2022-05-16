class Solution {
    int findPath(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i >= triangle.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + findPath(i+1, j, triangle, dp);
        int diag = triangle[i][j] + findPath(i+1, j+1, triangle, dp);
        
        return dp[i][j] = min(down, diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        return findPath(0, 0, triangle, dp);
    }
};