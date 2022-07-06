class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int prev = 0;
        
        for(int i = 2; i < n; i++) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                ans += prev+1;
                prev = prev+1;
            } else {
                prev = 0;
            }
        }
        
        return ans;
    }
};