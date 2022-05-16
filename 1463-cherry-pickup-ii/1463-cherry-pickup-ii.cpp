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
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        
        
        
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2)
                    dp[n-1][j1][j2] = grid[n-1][j1];
                else
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        
        for(int i = n-2; i >= 0; i--) {
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    int maxCherry = -1e8;
                    
                    for(int dj1 = -1; dj1 <= 1; dj1++) {
                        for(int dj2 = -1; dj2 <= 1; dj2++) {
                            int value = 0;
                            if(j1 == j2) {
                                value = grid[i][j1];
                            } else {
                                value = grid[i][j1] + grid[i][j2];
                            }
                            if(j1+dj1 <= m-1 && j1+dj1 >= 0 && j2+dj2 <= m-1 && j2+dj2 >= 0) {
                                value += dp[i+1][j1+dj1][j2+dj2];
                            } else {
                                value += -1e8;
                            }
                            
                            maxCherry = max(maxCherry, value);
                        }
                    }
                    
                    dp[i][j1][j2] = maxCherry;
                }
            }
        }
        
        return dp[0][0][m-1];
        
    }
};