class Solution {
    int findPath(int r, int c, vector<vector<int>>& dungeon, vector<vector<int>>& dp) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        if(r == m-1 && c == n-1) return dungeon[r][c];
        if(r == m) return -1e8;
        if(c == n) return -1e8;
        
        if(dp[r][c] != -1) return dp[r][c];
        
        int right = findPath(r, c+1, dungeon, dp);
        int down = findPath(r+1, c, dungeon, dp);
        
        int maxHealth = max(right, down);
        
        dp[r][c] = dungeon[r][c];
        if(dungeon[r][c] >= 0 || maxHealth < 0) dp[r][c] += maxHealth;
        return dp[r][c];
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
//         for(int i = 0; i <= n; i++) {
//             dp[m-1][i] = -1e8;
//         }
        
//         for(int i = 0; i <= m; i++) {
//             dp[i][n-1] = -1e8;
//         }
        
//         dp[m-1][n-1] = dungeon[m-1][n-1];
        
//         for(int r = m-1; r >= 0; r--) {
//             for(int c = n-1; c >= 0; c--) {
//                 int right = dp[r][c+1];
//                 int down = dp[r+1][c];

//                 int maxHealth = max(right, down);

//                 dp[r][c] = dungeon[r][c];
//                 if(dungeon[r][c] >= 0 || maxHealth < 0) dp[r][c] += maxHealth;
//             }
//         }
        
//         cout << dp[0][0];
//         return max(-dp[0][0], 0)+1;
        int ans = findPath(0, 0, dungeon, dp);
        if(ans <= 0) return -ans + 1;
        
        return 1;
    }
};