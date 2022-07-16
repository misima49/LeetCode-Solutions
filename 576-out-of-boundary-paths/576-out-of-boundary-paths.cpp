#define dir vector<int>({0, 1, 0, -1, 0})
#define mod 1000000007
class Solution {
    vector<vector<vector<int>>> dp;
public:
    Solution() : dp(vector<vector<vector<int>>>(51, vector<vector<int>>(51, vector<int>(52, -1)))) {}
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(startRow == m or startColumn == n or startRow < 0 or startColumn < 0) {
            return 1;
        }
        
        // cout << startRow << startColumn << "\n";
        
        if(maxMove == 0) return 0;
        
        if(dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];
        
        int ways = 0;
        for(int i = 0; i < 4; i++) {
            int x = startRow + dir[i];
            int y = startColumn + dir[i+1];
            ways =  ways%mod + findPaths(m, n, maxMove-1, x, y)%mod;
        }
        
        return dp[startRow][startColumn][maxMove] = ways%mod;
    }
};