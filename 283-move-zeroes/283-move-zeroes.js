/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let i = 0, j = 1;
    
    let n = nums.length;
    
    while(i < n && j < n) {
        if(nums[i] == 0) {
            if(nums[j] == 0) {
                j++;
            } else {
                [nums[i], nums[j]] = [nums[j], nums[i]];
            }
        } else {
            i++;
            j++;
        }
    }
};