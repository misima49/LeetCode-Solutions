class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int st = 0, ed = 0;
        int curSum = 0;
        int minLen = 1e8;
        
        while(ed < nums.size()) {
            curSum += nums[ed];
            
            if(curSum >= target) {
                while(st <= ed && curSum-nums[st] >= target) {
                    curSum -= nums[st];
                    st++;
                }
                minLen = min(minLen, ed-st+1);
            }
            
            ed++;
        }
        
        if(minLen == 1e8) return 0;
        return minLen;
    }
};