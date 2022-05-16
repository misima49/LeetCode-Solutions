class Solution {
    int findPath(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i >= triangle.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + findPath(i+1, j, triangle, dp);
        int diag = triangle[i][j] + findPath(i+1, j+1, triangle, dp);
        
        return dp[i][j] = min(down, diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prev(triangle.size());
        vector<int> cur(triangle.size());
        
        int i = triangle.size() - 1;
        int j;
        
        for( ; i >= 0; i--) {
            for(j = i ; j >= 0; j--) {
                if(i == triangle.size()-1) {
                    cur[j] = triangle[i][j];
                    continue;
                }
                
                int down = triangle[i][j] + prev[j];
                int diag = triangle[i][j] + prev[j+1];
                
                cur[j] = min(down, diag);
            }
            
            prev = cur;
        }
        
        return prev[0];
    }
};