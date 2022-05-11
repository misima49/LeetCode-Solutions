class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> reqTri;
        vector<int> curRow;
        reqTri.push_back({1});
        for(int i = 1; i < numRows; i++) {
            curRow.clear();
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    curRow.push_back(1);
                } else {
                    curRow.push_back(reqTri[i-1][j-1] + reqTri[i-1][j]);
                }
            }
            
            reqTri.push_back(curRow);
        }
        
        return reqTri;
    }
};