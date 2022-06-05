class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(2, 0), cur(2, 0);
        
        
        
        for(int i = n-1; i >= 0; i--) {
            int pick = 0;
            int notPick = 0;
            pick = nums[i] + next[false];
            notPick = next[true];
            
            cur[true] = max(pick, notPick);
            cur[false] = notPick;
            
            next = cur;
            
        }
        
        return next[true];
    }
};