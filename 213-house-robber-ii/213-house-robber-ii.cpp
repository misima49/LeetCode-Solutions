class Solution {
    int maxProfit(vector<int>& nums, int start, int end) {
        int pick, nonPick;
        int prev = 0, prev2 = 0;
        int curr;
        for(int i = start; i < end; i++) {
            pick = nums[i] + prev2;
            nonPick = prev;
            
            curr = max(pick, nonPick);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        
        int profitWithFirst = maxProfit(nums, 0, nums.size()-1);
        int profitWithLast = maxProfit(nums, 1, nums.size());
        return max(profitWithFirst, profitWithLast);
    }
};