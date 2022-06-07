class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxCount = 0;
        for(int i:nums) {
            if(i == 1) count++;
            else count = 0;
            
            if(count > maxCount) maxCount = count;
        }
        
        return maxCount;
    }
};