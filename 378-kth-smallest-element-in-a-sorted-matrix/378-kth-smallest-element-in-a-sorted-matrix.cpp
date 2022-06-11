class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> maxH;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                maxH.push(matrix[i][j]);
                if(maxH.size() > k)
                    maxH.pop();
            }
        }
        
        return maxH.top();
    }
};