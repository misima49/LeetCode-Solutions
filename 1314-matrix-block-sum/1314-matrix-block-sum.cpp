class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> preSum(m+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                preSum[i][j] = mat[i-1][j-1];
                if(j > 0) preSum[i][j] += preSum[i][j-1];
                if(i > 0) preSum[i][j] += preSum[i-1][j];
                if(i > 0 && j > 0) preSum[i][j] -= preSum[i-1][j-1];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int rF = min(i+k, m-1), cF = min(j+k, n-1);
                int rB = max(i-k, 0), cB = max(j-k, 0);
                
                rF++; cF++; rB++; cB++;
                
                ans[i][j] = preSum[rF][cF] - preSum[rB-1][cF] - preSum[rF][cB-1] + preSum[rB-1][cB-1];
            }
        }
        
        return ans;
    }
};