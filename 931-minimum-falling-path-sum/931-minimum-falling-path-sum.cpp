class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0), cur(n, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(i == n-1) {
                    cur[j] = matrix[i][j];
                    continue;
                }
                
                int up = prev[j];
                int leftDiag = INT_MAX;
                int rightDiag = INT_MAX;
                
                if(j > 0) leftDiag = prev[j-1];
                if(j < n-1) rightDiag = prev[j+1];
                
                cur[j] = matrix[i][j] + min({up, leftDiag, rightDiag});
            }
            
            prev = cur;
        }
        
        return *min_element(prev.begin(), prev.end());
    }
};