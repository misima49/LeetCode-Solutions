#define dir vector<int>({0,1,1,-1,0,-1,-1,1,0})

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1 || grid[grid.size()-1][grid.size()-1] == 1) return -1;
        if(grid.size() == 1) return 1;
        
        return bfs(grid);
    }
    
private:
    bool isValid(int r, int c, int n) {
        if(r < 0 || c < 0 || r >= n || c >= n) return false;
        return true;
    }
    
    int bfs(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        int steps = 1;
        bool foundEnd = false;
        grid[0][0] = 1;
        q.emplace(0, 0);
        
        while(!q.empty()) {
            ++steps;
            int sz = q.size();
            // cout << "sz " << sz << "\n";
            while(sz--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = 0; i < 8; i++) {
                    int x = r+dir[i];
                    int y = c+dir[i+1];
                    if(isValid(x, y, n) && grid[x][y] == 0) {
                        if(x == n-1 && y == n-1) {
                            return steps;
                        }
                        q.emplace(x, y);
                        grid[x][y] = 1;
                    }
                    
                    if(foundEnd) break;
                }
            }
            
        }
        
        return -1;
    }
};