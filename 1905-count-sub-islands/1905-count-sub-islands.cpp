class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int subIslandCount = 0;
        for(int i = 0; i < m; i++) {
            for(int j= 0; j < n; j++) {
                if(grid2[i][j] == 1) {
                    subIslandCount += dfs(i, j, grid2, grid1);
                }
            }
        }
        
        return subIslandCount;
    }
private:
    bool isValid(int r, int c, int rlen, int clen) {
        if(r < 0 || c < 0 || r >= rlen || c >= clen) return false;
        return true;
    }
    
    bool dfs(int R, int C, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        bool isSubIsland = true;
        if(grid1[R][C] != grid2[R][C]) isSubIsland = false;
        int dir[5] = {0, 1, 0, -1, 0};
        int rlen = grid1.size(), clen = grid1[0].size();
        stack<pair<int, int>> st;
        st.push({R, C});
        grid1[R][C] = 0;
        
        while(!st.empty()) {
            int r = st.top().first;
            int c = st.top().second;
            bool flag = false;
            
            for(int i = 0; i < 4; i++) {
                int x = r+dir[i];
                int y = c+dir[i+1];
                if(isValid(x, y, rlen, clen)) {
                    if(grid1[x][y] == 1 && grid2[x][y] != 1) isSubIsland = false;
                    if(grid1[x][y] == 1 && grid2[x][y] == 1) {
                        st.push({x, y});
                        grid1[x][y] = 0;
                        flag = true;
                    }
                }
            }
            
            if(!flag) {
                st.pop();
            }
        }
        
        return isSubIsland;
        
    }
};