class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == '1') {
                    islandCount++;
                    dfs(r, c, grid);
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
    
    void dfs(int R, int C, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        stack<pair<int, int>> st;
        vector<int> dir({0, 1, 0, -1, 0});
        grid[R][C] = '0';
        st.push({R, C});
        
        while(!st.empty()) {
            bool flag = false;
            int x = st.top().first;
            int y = st.top().second;
            
            for(int i = 0; i < 4; i++) {
                int curR = x+dir[i], curC = y+dir[i+1];
                if(isValid(curR, curC, m, n) && grid[curR][curC] == '1') {
                    st.push({curR, curC});
                    grid[curR][curC] = '0';
                    flag = true;
                }
            }
            
            if(!flag) {
                st.pop();
            }
        }
    }
};