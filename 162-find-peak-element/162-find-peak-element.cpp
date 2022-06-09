class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st = 0, ed = nums.size()-1;
        int md = (st+ed)/2;
        
        while(st < ed) {
            if((md == 0 || nums[md-1] < nums[md]) &&
               (nums[md+1] < nums[md] || md == nums.size()-1)) return md;
            
            if(nums[md] < nums[md+1]) st = md+1;
            else ed = md-1;
            
            md = (st+ed)/2;
        }
        
        return md;
    }
};