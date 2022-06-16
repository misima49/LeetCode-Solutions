#define dir vector<int>({0, 1, 0, -1, 0})
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> atlan_visit(m, vector<bool>(n, false)), 
            pacif_visit(m, vector<bool>(n, false));
        queue<pair<int, int>> atlan_q, pacif_q;
        
        for(int i = 0; i < n; i++) {
            pacif_visit[0][i] = true;
            pacif_q.push({0, i});
            
            atlan_visit[m-1][i] = true;
            atlan_q.push({m-1, i});
        }
        
        for(int j = 0; j < m; j++) {
            pacif_visit[j][0] = true;
            pacif_q.emplace(j, 0);
            
            atlan_visit[j][n-1] = true;
            atlan_q.emplace(j, n-1);
        }
        
        bfs(pacif_q, pacif_visit, heights);
        bfs(atlan_q, atlan_visit, heights);
        
        vector<vector<int>> ans;
        
        for(int i = 0;  i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(atlan_visit[i][j] && pacif_visit[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
    
private:
    bool isValid(int r, int c, int m, int n) {
        if(r < 0 || c < 0 || r >= m || c >= n) return false;
        return true;
    }
    
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& visited,
                    vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int x = r+dir[i];
                int y = c+dir[i+1];
                if(isValid(x, y, m, n) && heights[r][c] <= heights[x][y]
                  && !visited[x][y]) {
                    visited[x][y] = true;
                    q.emplace(x, y);
                }
            }
        }
    }
};