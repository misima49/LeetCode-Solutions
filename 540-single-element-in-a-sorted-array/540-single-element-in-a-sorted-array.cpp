class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0, ed = nums.size()-1;
        int md = (st+ed)/2;
        
        while(st <= ed) {
            if((md <= 0 || nums[md] != nums[md-1]) &&
               (md+1 > nums.size()-1 || nums[md] != nums[md+1])) {
                return nums[md];
            }
            
            
            if(md % 2 == 0) {
                if(nums[md] == nums[md+1]) {
                    st = md+1;
                } else {
                    ed = md-1;
                }
            } else {
                if(nums[md] == nums[md+1]) {
                    ed = md-1;
                } else {
                    st = md+1;
                }
            }
            
            
            md = (st+ed)/2;
        }
        // cout << "here";
        return nums[md];
    }
};