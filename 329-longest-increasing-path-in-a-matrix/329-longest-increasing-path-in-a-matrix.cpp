#define dir vector<int>({0, 1, 0, -1, 0})

class Solution {
    bool isValid(int r, int c, int m, int n) {
        if(r < 0 || c < 0 || r >= m || c >= n) return false;
        return true;
    }
    int findLIS(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        // cout << r << " " << c << "\n";
        int m = matrix.size();
        int n = matrix[0].size();
        if(r >= m || c >= n || r < 0 || c < 0) return 0;
        
        if(dp[r][c] != -1) return dp[r][c];
        
        int curPathLen = 1;
        for(int i = 0; i < 4; i++) {
            int x = r+dir[i];
            int y = c+dir[i+1];
            if(isValid(x, y, m, n) && matrix[x][y] > matrix[r][c]) {
                curPathLen = max(curPathLen, 1 + findLIS(x, y, matrix, dp));
            }
        }
        
        return dp[r][c] = curPathLen;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j] == -1) 
                    ans = max(ans, findLIS(i, j, matrix, dp));
            }
        }
        
        
        return ans;
    }
};