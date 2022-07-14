class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int curPre = 1;
        int curSuf = 1;
        for(int i = 0; i < n; i++) {
            ans.push_back(curPre);
            curPre *= nums[i];
        }
        
        for(int i = n-1; i >= 0; i--) {
            ans[i] *= curSuf;
            curSuf *= nums[i];
        }
        return ans;
    }
};