#define dir vector<int>({0, 1, 0, -1, 0})


class Solution {
    int dp[200][200]{};
    int ans, m, n;
    int findLIS(int r, int c, vector<vector<int>>& matrix, int prev) {
            if(r >= m || c >= n || r < 0 || c < 0 || matrix[r][c] <= prev) return 0;
        
        if(dp[r][c]) return dp[r][c];
        for(int i = 0; i < 4; i++) {
            int x = r+dir[i];
            int y = c+dir[i+1];
            dp[r][c] = max(dp[r][c], findLIS(x, y, matrix, matrix[r][c]));
        }
        
        return ++dp[r][c];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) 
                ans = max(ans, findLIS(i, j, matrix, -1));
        
        return ans;
    }
};