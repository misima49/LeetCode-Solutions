class Solution {
    void solve(int col,vector<string>& curSol, vector<vector<string>>& result, int n, unordered_map<int, bool>& leftRow, unordered_map<int, bool>& lowerDiag, unordered_map<int, bool>& upperDiag) {
        if(col == n) {
            result.push_back(curSol);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(leftRow[row] == true || lowerDiag[row+col] == true || upperDiag[n-1 + col-row]) continue;
            leftRow[row] = true;
            lowerDiag[row+col] = true;
            upperDiag[n-1 + col-row] = true;
            curSol[row][col] = 'Q';
            
            solve(col+1, curSol, result, n, leftRow, lowerDiag, upperDiag);
            
            leftRow[row] = false;
            lowerDiag[row+col] = false;
            upperDiag[n-1 + col-row] = false;
            curSol[row][col] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string inti = string(n, '.');
        vector<string> curSol(n, inti);
        unordered_map<int, bool> leftRow;
        unordered_map<int, bool> lowerDiag;
        unordered_map<int, bool> upperDiag;
        
        for(int i = 0; i < n; i++) {
            leftRow.insert({i, false});
        }
        
        for(int i = 0; i < 2*n-1; i++) {
            lowerDiag.insert({i, false});
        }
        
        for(int i = 0; i < 2*n-1; i++) {
            upperDiag.insert({i, false});
        }
        
        solve(0, curSol, result, n, leftRow, lowerDiag, upperDiag);
        
        return result;
    }
};