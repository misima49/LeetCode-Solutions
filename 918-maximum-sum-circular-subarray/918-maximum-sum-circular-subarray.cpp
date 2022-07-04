class Solution {
    int maxSubarr(vector<int>& nums) {
        int n = nums.size();
        int curSum = 0;
        int maxSum = nums[0];
        
        for(int i : nums) {
            if(curSum < 0) curSum = 0;
            curSum = curSum + i;
            maxSum = max(curSum, maxSum);
        }
        
        return maxSum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxInArray = maxSubarr(nums);
        int totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
            nums[i] = -nums[i];
        }
        
        int minInArray = maxSubarr(nums);
        minInArray += totalSum;
        
        if(minInArray == 0) return maxInArray;
        return max(minInArray, maxInArray);
    }
};