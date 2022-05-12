class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int dime = matrix.size();
        for(int i = 0; i < dime; i++) {
            for(int j = i; j < dime; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i = 0; i < dime; i++) {
            for(int j = 0; j < dime/2; j++) {
                swap(matrix[i][j], matrix[i][dime-j-1]);
            }
        }
    }
};