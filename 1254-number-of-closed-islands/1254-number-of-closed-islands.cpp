class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rlen = grid.size();
        int clen = grid[0].size();
        int islandCount = 0;
        
        for(int i = 0; i < rlen; i++) {
            for(int j = 0; j < clen; j++) {
                if(grid[i][j] == 0) {
                    if(dfs(i, j, grid)) islandCount++;
                }
            }
        }
        
        return islandCount;
    }

private:
    bool isValid(int r, int c, int rlen, int clen) {
        if(r < 0 || c < 0 || r >= rlen || c >= clen) return false;
        return true;
    }
    
    bool dfs(int R, int C, vector<vector<int>>& grid) {
        int dir[5] = {0, 1, 0, -1, 0};
        int rlen = grid.size(), clen = grid[0].size();
        bool isEdgeFound = false;
        stack<pair<int, int>> st;
        st.push({R, C});
        grid[R][C] = 1;
        
        while(!st.empty()) {
            int r = st.top().first;
            int c = st.top().second;
            bool flag = false;
            
            for(int i = 0; i < 4; i++) {
                int x = r+dir[i];
                int y = c+dir[i+1];
                if(isValid(x, y, rlen, clen)) {
                    if(grid[x][y] == 0) {
                        st.push({x, y});
                        grid[x][y] = 1;
                        flag = true;
                    }
                } else {
                    isEdgeFound = true;
                }
            }
            
            if(!flag) {
                st.pop();
            }
        }
        
        if(isEdgeFound)
            return false;
        
        return true;
        
    }
};