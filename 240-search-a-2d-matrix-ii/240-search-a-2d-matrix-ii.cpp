class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0, c = n-1;
        
        while(r < m && c >= 0) {
            int cur = matrix[r][c];
            if(cur == target) return true;
            if(cur < target) {
                r++;
            } else {
                c--;
            }
        }
        
        return false;
    }
};