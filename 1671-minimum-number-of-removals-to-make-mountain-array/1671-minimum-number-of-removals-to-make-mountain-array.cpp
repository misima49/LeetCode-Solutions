class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i] && dp1[i] < dp1[j]+1) {
                    dp1[i] = 1+dp1[j];
                }
            }
        }
        
        vector<int> dp2(n, 1);
        int maxLen = 1;
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j > i; j--) {
                if(nums[j] < nums[i] && dp2[i] < dp2[j]+1) {
                    dp2[i] = 1+dp2[j];
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(dp1[i] != 1 && dp2[i] != 1) {
                maxLen = max(maxLen, dp1[i]+dp2[i]-1);
            }
        }
        
        return n-maxLen;
    }
};