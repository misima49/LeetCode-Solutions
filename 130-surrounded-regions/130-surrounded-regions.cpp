#define dir vector<int>({0,1,0,-1,0})

class Solution {
    bool isValid(int r, int c, int m, int n) {
        if(r < 0 || c < 0 || r >= m || c >= n) return false;
        return true;
    }
    
    int findParent(int ind, vector<int>& parent) {
        if(parent[ind] < 0) return ind;
        return parent[ind] = findParent(parent[ind], parent);
    }
    
    void unionn(int x, int y, vector<int>& parent) {
        int u = findParent(x, parent);
        int v = findParent(y, parent);
        
        if(u == v) return;
        if(u > v) swap(u, v);
        if(v == parent.size()-1) swap(u, v);
        
        parent[u] += parent[v];
        parent[v] = u;
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<int> parent(m*n+1, -1);
        
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(board[r][c] == 'O') {
                    if(r == 0 || c == 0 || r == m-1 || c == n-1) {
                        unionn(r*n+c, m*n, parent);
                    } else {
                        for(int i = 0; i < 4; i++) {
                            int x = r+dir[i], y = c+dir[i+1];
                            if(isValid(x, y, m, n) && board[x][y] == 'O')
                                unionn(r*n+c, x*n+y, parent);
                        }
                    }
                }
            }
        }
        
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(board[r][c] == 'O' && findParent(r*n+c, parent) != m*n)
                    board[r][c] = 'X';
            }
        }
    }
};