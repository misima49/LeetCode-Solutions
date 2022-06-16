#define dir vector<int>({0, 1, 0, -1, 0})
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int maxDist = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    for(int itr = 0; itr < 4; itr++) {
                        int x = i+dir[itr];
                        int y = j+dir[itr + 1];
                        q.push({x, y});
                    }
                }
            }
        }
        
        int ans = bfs(q, grid);
        return (ans == 1) ? -1 : ans-1;
    }
private:
    bool isValid(int r, int c, int dimen) {
        if(r < 0 || c < 0 || r >= dimen || c >= dimen) return false;
        return true;
    }
    
    int bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        int dimen = grid.size();
        int curDist = 0;
        
        while(!q.empty()) {
            int n = q.size();
            curDist++;
            while(n--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                if(isValid(r, c, dimen) && grid[r][c] == 0) {
                    grid[r][c] = curDist;
                    for(int i = 0; i < 4; i++) {
                        int x = r+dir[i];
                        int y = c+dir[i+1];       
                        q.push({x, y});
                    }
                }
            }
            
        }
        
        return curDist;
    }
};