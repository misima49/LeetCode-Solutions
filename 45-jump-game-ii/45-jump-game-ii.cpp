class Solution {
    int findJumps(int ind, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if(ind >= n) return 0;
        if(ind == n-1) return dp[ind] = 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int minJumps = 1e8;
        for(int i = ind+nums[ind]; i > ind; i--) {
            minJumps = min(minJumps, findJumps(i, nums, dp));
        }
        
        return dp[ind] = 1+minJumps;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        // for(int i = 0; i < n; i++) {
        //     int minJumps = 1e8;
        //     for(int j = i+nums[i]; j > i; j--) {
        //         minJumps = 
        //     }
        // }
        
        return findJumps(0, nums, dp);
    }
};