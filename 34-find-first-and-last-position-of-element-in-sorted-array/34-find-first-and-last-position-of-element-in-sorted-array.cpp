class Solution {
    vector<int> ans;
    
    void binarySearch(vector<int>& nums, int& target, int st, int ed) {
        if(st > ed) return;
        
        int md = st + (ed-st)/2;
        
        // cout << st << " "  << ed << nums[md] << '\n';
        if(nums[md] == target) {
            ans[0] = ans[0] < md ? ans[0] : md;
            ans[1] = ans[1] > md ? ans[1] : md;
            
            if(md > 0 && nums[md-1] == target) binarySearch(nums, target, st, md-1);
            if(md+1 < nums.size() && nums[md+1] == target) binarySearch(nums, target, md+1, ed);
        } else if(nums[md] > target) {
            binarySearch(nums, target, st, md-1);
        } else {
            binarySearch(nums, target, md+1, ed);
        }
    }
public:
    Solution() : ans({INT_MAX, INT_MIN}) {};
    vector<int> searchRange(vector<int>& nums, int target) {
        // ans[0] = INT_MIN;
        // ans[1] = INT_MAX;
        binarySearch(nums, target, 0, nums.size()-1);
        
        if(ans[0] == INT_MAX || ans[1] == INT_MIN) return {-1, -1};
        return ans;
    }
};