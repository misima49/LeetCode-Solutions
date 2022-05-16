/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let curEl, count = 0;
    
    for(let i = 0; i < nums.length; i++) {
        if(count == 0) {
            curEl = nums[i];
            count++;
        } else {
            if(curEl == nums[i]) count++;
            else count--;
        }
    }
    
    console.log(count);
    
    return curEl;
};