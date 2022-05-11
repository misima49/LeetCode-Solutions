class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int largestSum = INT_MIN;
        for(int itr : nums) {
            curSum += itr;
            largestSum = max(largestSum, curSum);
            if(curSum < 0) 
                curSum = 0;
        }
        
        return largestSum;
    }
};