class Solution {
public:
    bool isValid(int r, int c, int rlen, int clen) {
        return (r >= 0 && c >= 0 && r < rlen && c < clen);
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> result(mat.size(), vector<int>(mat[0].size(), INT_MAX-100));
        queue<pair<int, int>> q;
        int next, prev, lower, upper;
        int rLen = mat.size();
        int cLen = mat[0].size();
        
        
        for(int i = 0; i < rLen; i++) {
            for(int j = 0; j < cLen; j++) {
                if(mat[i][j] == 0) {
                    result[i][j] = 0;
                } else {
                    if(isValid(i-1, j, rLen, cLen)) {
                        result[i][j] = min(result[i][j], result[i-1][j]+1);
                    }
                    
                    if(isValid(i, j-1, rLen, cLen)) {
                        result[i][j] = min(result[i][j], result[i][j-1]+1);
                    }
                }
            }
        }
        
        for(int i = rLen - 1; i >= 0; i--) {
            for(int j = cLen - 1; j >= 0; j--) {
                if(mat[i][j] == 0) {
                    result[i][j] = 0;
                } else {
                    if(isValid(i+1, j, rLen, cLen)) {
                        result[i][j] = min(result[i][j], result[i+1][j]+1);
                    }
                    
                    if(isValid(i, j+1, rLen, cLen)) {
                        result[i][j] = min(result[i][j], result[i][j+1]+1);
                    }
                }
            }
        }
        
        return result;
    }
};