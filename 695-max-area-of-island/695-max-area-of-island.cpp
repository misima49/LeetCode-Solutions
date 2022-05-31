class Solution {
    bool isValid(int r, int c, int rlen, int clen) {
        if(r < rlen && c < clen && r >= 0 && c >= 0) return true;
        return false;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rlen = grid.size();
        int clen = grid[0].size();
        int cur, largest = 0;
        
        stack<pair<int, int>> st;
        
        for(int i = 0; i < rlen; i++) {
            for(int j = 0; j < clen; j++) {
                if(grid[i][j] == 1) {
                    st.push({i, j});
                    grid[i][j] = 0;
                    cur = 0;
                    while(!st.empty()) {
                        int x = st.top().first;
                        int y = st.top().second;
                        st.pop();
                        // cout << x << " " << y << "\n";
                        cur++;
                        
                        if(isValid(x+1, y, rlen, clen) && grid[x+1][y] == 1) {
                            st.push({x+1, y});
                            grid[x+1][y] = 0;
                        }
                        if(isValid(x-1, y, rlen, clen) && grid[x-1][y] == 1) {
                            st.push({x-1, y});
                            grid[x-1][y] = 0;
                        }
                        if(isValid(x, y+1, rlen, clen) && grid[x][y+1] == 1) {
                            st.push({x, y+1});
                            grid[x][y+1] = 0;
                        }
                        if(isValid(x, y-1, rlen, clen) && grid[x][y-1] == 1) {
                            st.push({x, y-1});
                            grid[x][y-1] = 0;
                        }
                    }
                    // cout << "\n";
                    largest = max(largest, cur);
                }
            }
        }
        
        return largest;
    }
};