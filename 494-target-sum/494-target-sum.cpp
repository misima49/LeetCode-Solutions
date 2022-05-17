class Solution {
    int findSum(int ind, int target, vector<int>& nums) {
        if(ind < 0) {
            if(target == 0) return 1;
            return 0;
        }
        
        int posi = findSum(ind-1, target-nums[ind], nums);
        int neg = findSum(ind-1, target+nums[ind], nums);
        
        // cout << posi << " " << neg << "\n";
        
        return posi + neg;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return findSum(nums.size()-1, target, nums);
    }
};