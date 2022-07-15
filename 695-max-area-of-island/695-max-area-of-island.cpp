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
        int dir[] = {0, 1, 0, -1, 0};
        
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
                        cur++;
                        for(int itr = 0; itr < 4; itr++) {
                            int r = x+dir[itr];
                            int c = y+dir[itr+1];
                            if(isValid(r, c, rlen, clen) && grid[r][c] == 1) {
                                st.push({r, c});
                                grid[r][c] = 0;
                            }
                        }
                    }
                    largest = max(largest, cur);
                }
            }
        }
        
        return largest;
    }
};