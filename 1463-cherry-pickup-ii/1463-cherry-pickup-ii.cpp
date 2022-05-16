class Solution {
    int findMaxCherry(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if(j1 < 0 || j1 > m-1 || j2 < 0 || j2 > m-1) {
            return -1e8;
        }
        if(i == n-1) {
            if(j1 == j2) 
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxCherry = 0;
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                maxCherry = max(maxCherry, findMaxCherry(i+1, j1+dj1, j2+dj2, grid, dp));
            }
        }
        
        // cout << maxCherry << "for " << i << j1 << j2<< "\n";
        if(j1 == j2)
            return dp[i][j1][j2] = grid[i][j1] + maxCherry;
        else
            return dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + maxCherry;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return findMaxCherry(0, 0, m-1, grid, dp);
    }
};