class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int st = 0;
        int ed = m*n - 1;
        int md = (st+ed)/2;
        
        while(st <= ed) {
            // cout << st << " " << md << " " << ed << "\n";
            if(matrix[md/n][md%n] == target) return true;
            
            if(matrix[md/n][md%n] <= target) {
                st = md+1;
            } else {
                ed = md-1;
            }
            // cout << "here";
            md = (st+ed)/2;
        }
        
        return false;
    }
};