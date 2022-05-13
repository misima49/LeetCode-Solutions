/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let sum = 0;
    let n = nums.length;
    for(let itr in nums) {
        sum += nums[itr];
    }
    
    return (n*(n+1)/2 - sum);
};