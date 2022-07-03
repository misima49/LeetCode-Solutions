vector<int> dir({0,1,0,-1,0});
#define mod 1000000007
class Solution {
    
    bool isValid(int r, int c, int m, int n) {
        if(r >= m || c >= n || r < 0 || c < 0) return false;
        return true;
    }
    int findPath(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(dp[r][c] != -1) return dp[r][c];
        
        int ans = 0;
        for(int i = 0; i < 4; i++) {
            int x = r+dir[i];
            int y = c+dir[i+1];
            if(isValid(x, y, m, n) && grid[x][y] > grid[r][c]) {
                ans += findPath(x, y, grid, dp)%mod;
            }
        }
        
        return dp[r][c] = (1+ans)%mod;
    }
    
public:
    int countPaths(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans += findPath(i, j, grid, dp);
                ans %= mod;
            }
        }
        return ans%mod;
    }
};