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
        
        vector<int> prevRow(n+1, -1e8);

        prevRow[n-1] = dungeon[m-1][n-1];

        for(int r = m-1; r >= 0; r--) {
            for(int c = n-1; c >= 0; c--) {
                if(r == m-1 && c == n-1) continue;

                int maxHealth = max(prevRow[c], prevRow[c+1]);
                prevRow[c] = dungeon[r][c];
                if(dungeon[r][c] >= 0 || maxHealth < 0) prevRow[c] += maxHealth;
            }
        }

        return max(-prevRow[0], 0)+1;
    }
};