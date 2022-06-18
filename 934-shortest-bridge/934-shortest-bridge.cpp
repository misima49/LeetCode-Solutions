#define dir vector<int>({0, 1, 0, -1, 0})

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool flag = false;
        queue<pair<int, int>> q1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q1 = setIslandOne(i, j, grid);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        
        return findIslandTwo(q1, grid) - 2;
    }
private:
    bool isValid(int r, int c, int n) {
        if(r < 0 || c < 0 || r >= n || c >= n) return false;
        return true;
    }
    
    queue<pair<int, int>> setIslandOne(int R, int C, vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        queue<pair<int, int>> q2;
        q.emplace(R, C);
        grid[R][C] = 2;
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q2.emplace(r, c);
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int x = r+dir[i];
                int y = c+dir[i+1];
                if(isValid(x, y, n) && grid[x][y] == 1) {
                    grid[x][y] = 2;
                    q.emplace(x, y);
                }
            }
        }
        
        return q2;
    }
    
    int findIslandTwo(queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        int n = grid.size();
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            cout << r << " " << c << "\n";
            for(int i = 0; i < 4; i++) {
                int x = r+dir[i];
                int y = c+dir[i+1];
                
                if(isValid(x, y, n)) {
                    if(grid[x][y] == 0) {
                        grid[x][y] = grid[r][c]+1;
                        q.emplace(x, y);
                    } else if(grid[x][y] == 1) {
                        // cout << grid[x][y] << " " << x << " " << y << "\n";
                        return grid[r][c];
                    }
                }
            }
        }
        
        return -1;
    }
};