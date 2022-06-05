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
        vector<int> next(n+1, 0), cur(n+1, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                int down = next[j];
                int diag = next[j+1];
                
                cur[j] = triangle[i][j] + min(down, diag);
            }
            
            next = cur;
        }
        
        return next[0];
    }
};