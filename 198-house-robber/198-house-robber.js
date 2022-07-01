/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    const n = nums.length
    let nex = 0, nex2 = 0
    
    for(let i = n-1; i >= 0; i--) {
        let pick = nums[i] + nex2
        let notPick = nex
        // console.log(pick, notPick)
        nex2 = nex
        nex = (pick < notPick) ? notPick : pick
    }
    
    return nex
};