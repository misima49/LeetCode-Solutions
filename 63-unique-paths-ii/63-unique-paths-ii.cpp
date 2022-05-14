class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        vector<int> prev(obstacle[0].size(), 0);
        
        if(obstacle[0][0] == 1) return 0;
        
        
        for(int i = 0; i < obstacle.size(); i++) {
            vector<int> cur(obstacle[0].size(), 0);
            
            for(int j = 0; j < obstacle[0].size(); j++) {
                if(i == 0 && j == 0) {
                    cur[j] = 1;
                    continue;
                }
                
                if(obstacle[i][j] == 1) {
                    cur[j] = 0;
                    continue;
                }
                
                if(i > 0) cur[j] += prev[j];
                if(j > 0) cur[j] += cur[j-1];
            }
            
            prev = cur;
        }
        
        return prev[obstacle[0].size()-1];
    }
};