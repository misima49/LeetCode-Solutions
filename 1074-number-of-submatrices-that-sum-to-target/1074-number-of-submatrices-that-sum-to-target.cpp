class Solution {
    int ans = 0, target;
    void find_row_ans(vector<int>& row) {
        // int n = row.size();
        int curSum = 0;
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        
        for(int itr : row) {
            curSum += itr;
            if(sumCount.count(curSum-target)) {
                ans += sumCount[curSum-target];
            }
            
            sumCount[curSum]++;
        }
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        this->target = target;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(n);
        
        for(int i = 0; i < m; i++) {
            fill(row.begin(), row.end(), 0);
            
            for(int r = i; r < m; r++) {
                for(int c = 0; c < n; c++) {
                    row[c] += matrix[r][c];
                }
                
                find_row_ans(row);
            }
        }
        
        return ans;
    }
};