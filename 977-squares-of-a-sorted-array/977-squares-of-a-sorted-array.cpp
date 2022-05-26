class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int end = nums.size()-1;
        int start = 0;
        int itr = nums.size()-1;
        vector<int> ans(nums.size());
        while(start <= end) {
            if(nums[start]*nums[start] > nums[end]*nums[end]) {
                ans[itr--] = nums[start]*nums[start++];
            } else {
                ans[itr--] = nums[end]*nums[end--];
            }
        }
        
        return ans;
    }
};