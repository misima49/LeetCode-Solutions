class Solution {
    int findPath(int i, int j, vector<vector<int>>& matrix) {
        if(j < 0 || j > matrix.size()-1) {
            return INT_MAX-100;
        }
        if(i == 0) {
            return matrix[i][j];
        }
        
        int down = matrix[i][j] + findPath(i-1, j, matrix);
        int leftDiag = matrix[i][j] + findPath(i-1, j-1, matrix);
        int rightDiag = matrix[i][j] + findPath(i-1, j+1, matrix);
        
        cout << min({down, leftDiag, rightDiag}) << " at " << matrix[i][j] << "\n";
        
        return min({down, leftDiag, rightDiag});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0), cur(n, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(i == n-1) {
                    cur[j] = matrix[i][j];
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