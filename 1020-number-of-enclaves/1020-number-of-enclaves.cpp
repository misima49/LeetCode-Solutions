class Solution {
    bool isValid(int R, int C, int rlen, int clen) {
        if(R < 0 || C < 0 || R >= rlen || C >= clen) return false;
        return true;
    }
    
    int dfs(int R, int C,vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islandCount = 0;
        bool edgeFound = false;
        int dir[5] = {0, 1, 0, -1, 0};
        stack<pair<int, int>> st;
        
        st.push({R, C});
        islandCount++;
        grid[R][C] = 0;
        
        while(!st.empty()) {
            // int r = st.top().first;
            // int c = st.top().second;
            bool flag = false;
            
            for(int i = 0; i < 4; i++) {
                int x = st.top().first + dir[i];
                int y = st.top().second + dir[i+1];
                if(isValid(x, y, n, m)) {
                    if(grid[x][y] == 1) {
                        grid[x][y] = 0;
                        flag = true;
                        st.push({x, y});
                        islandCount++;
                        break;
                    }
                } else 
                    edgeFound = true;
            }
            
            if(!flag) {
                st.pop();
            }
        }
        
        if(!edgeFound)
            return islandCount;
        else
            return 0;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int edgeLandCount = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) 
                    edgeLandCount += dfs(i, j, grid);
            }
        }
        
        return edgeLandCount;
    }
};