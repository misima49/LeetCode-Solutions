class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int firstNeg = -1;
        int curSt = -1;
        int negCount = 0;
        int maxLen = 0;
        
        for(int i = 0 ; i < n; i++) {
            if(nums[i] == 0) {
                firstNeg = -1;
                negCount = 0;
                curSt = i;
            } else {
                if(nums[i] < 0) negCount++;
                if(negCount == 1 && firstNeg == -1) firstNeg = i;
                if(negCount % 2 == 0) maxLen = max(maxLen, i-curSt);
                else maxLen = max(maxLen, i-firstNeg);
            }
        }
        
        return maxLen;
    }
};