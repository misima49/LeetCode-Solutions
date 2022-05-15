class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int x = grid.size();
        int y = grid[0].size();
        vector<int> prev(y);
        
        for(int i = 0; i < x; i++) {
            vector<int> cur(y);
            for(int j = 0; j < y; j++) {
                if(i == 0 && j == 0) {
                    cur[j] = grid[i][j];
                    continue;
                }
                int left = INT_MAX;
                int up = INT_MAX;
                
                if(j > 0) left = cur[j-1] + grid[i][j];
                if(i > 0) up = prev[j] + grid[i][j];
                
                cur[j] = min(left, up);
            }
            
            prev = cur;
        }
        
        return prev[y-1];
    }
};