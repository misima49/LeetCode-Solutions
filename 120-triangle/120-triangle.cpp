class Solution {
    int findSum(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int n = triangle.size();
        if(i == n) return 0;;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + findSum(i+1, j, triangle, dp);
        int diag = triangle[i][j] + findSum(i+1, j+1, triangle, dp);
        
        return dp[i][j] = min(down, diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return findSum(0, 0, triangle, dp);
    }
};