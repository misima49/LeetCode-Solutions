/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves2 = function(nums) {
    let st = 0
    let ed = nums.length-1
    let ans = 0
    nums.sort((a, b) => a-b)
    while(st < ed) {
        ans += nums[ed] - nums[st]
        ed--
        st++
    }
    
    return ans
};