class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = false;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) {
                if(!flag) {
                    if(i-2 < 0 || nums[i-2] <= nums[i])
                        nums[i-1] = nums[i];
                    else
                        nums[i] = nums[i-1];
                    flag = true;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};