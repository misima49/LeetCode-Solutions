class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1, j = 1;
        
        while(j < n) {
            if(nums[j] != nums[j-1])
                nums[i++] = nums[j];
            j++;
        }
        
        return i;
    }
};