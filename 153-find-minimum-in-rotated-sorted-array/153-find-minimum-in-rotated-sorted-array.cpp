class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, ed = nums.size()-1;
        int md = (st+ed)/2;
        int mini = nums[md];
        while(st <= ed) {
            // if(nums[md] < mini) mini = nums[md];
            
            if(nums[st] <= nums[md]) {
                mini = min(mini, nums[st]);
                st = md+1;
            } else {
                mini = min(mini, nums[md]);
                ed = md-1;
            }
            
            md = (st+ed)/2;
        }
        
        return mini;
    }
};