class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int ed = nums.size()-1;
        int md = (ed-st)/2;
        while(st <= ed) {
            // cout << st << " " << md << " " << ed << "\n";
            if(nums[md] == target) return md;
            
            if(nums[st] <= nums[md]) {
                if(nums[st] <= target && target <= nums[md]) {
                    ed = md-1;
                } else {
                    st = md+1;
                }
            } else {
                if(nums[md] <= target && target <= nums[ed]) {
                    st = md+1;
                } else {
                    ed = md-1;
                }
            }
            
            md = st + (ed-st)/2;
        }
        
        return -1;
    }
};