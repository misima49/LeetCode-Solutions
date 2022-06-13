class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> next(n+1, 0), cur(n+1, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                int down = next[j];
                int diag = next[j+1];
                
                cur[j] = triangle[i][j] + min(down, diag);
            }
            
            next = cur;
        }
        
        return next[0];
    }
};