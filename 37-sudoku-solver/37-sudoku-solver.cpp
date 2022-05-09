class Solution {
    bool isValid(int row, int col, char c, vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == c || board[i][col] == c) return false;
            if(board[(row/3)*3 + i/3][(col/3)*3 + i%3] == c) return false;
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board.size(); col++) {
                if(board[row][col] == '.') {
                    for(int i = 1; i <= 9; ++i) {
                        if(isValid(row, col, i+48, board)) {
                            board[row][col] = i+48;
                            if(solve(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
};