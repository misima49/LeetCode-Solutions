class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> reqTri(numRows);
        reqTri[0] = {1};
        for(int i = 1; i < numRows; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    reqTri[i].push_back(1);
                } else {
                    reqTri[i].push_back(reqTri[i-1][j-1] + reqTri[i-1][j]);
                }
            }
        }
        
        return reqTri;
    }
};