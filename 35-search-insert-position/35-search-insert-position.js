/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let start = 0;
    let end = nums.length;
    let curMid;
    let lastGreater = nums.length - 1;
    
    while(start <= end) {
        curMid = start + Math.trunc((end - start)/2);
        if(nums[curMid] == target) {
            return curMid;
        }
        if(nums[curMid] < target) {
            start = curMid + 1;
        } else {
            lastGreater = curMid;
            end = curMid - 1;
        }
    }
    
    return lastGreater;
};