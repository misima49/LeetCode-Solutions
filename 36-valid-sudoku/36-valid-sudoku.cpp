class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> validRow(9, vector<bool>(10, false));
        vector<vector<bool>> validCol(9, vector<bool>(10, false));
        vector<vector<vector<bool>>> validSub(3, vector<vector<bool>>(3, vector<bool>(10, false)));

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                
                if(validRow[i][board[i][j]-'0']) return false;
                else validRow[i][board[i][j]-'0'] = true;

                if(validCol[j][board[i][j]-'0']) return false;
                else validCol[j][board[i][j]-'0'] = true;

                if(validSub[i/3][j/3][board[i][j]-'0']) return false;
                else validSub[i/3][j/3][board[i][j]-'0'] = true;
            }
        }
        
        return true;
    }
};