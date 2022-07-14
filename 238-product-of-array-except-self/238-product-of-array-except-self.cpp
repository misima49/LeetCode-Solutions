class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int curPre = 1;
        int curSuf = 1;
        for(int i = 0; i < n; i++) {
            ans[i] *= curPre;
            curPre *= nums[i];
            ans[n-i-1] *= curSuf;
            curSuf *= nums[n-i-1];
        }
        
        // for(int i = n-1; i >= 0; i--) {
        //     ans[i] *= curSuf;
        //     curSuf *= nums[i];
        // }
        return ans;
    }
};