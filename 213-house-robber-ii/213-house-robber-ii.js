/**
 * @param {number[]} nums
 * @return {number}
 */
var findProf = function(nums, st, n) {
    let nex = 0, nex2 = 0
    
    for(let i = n-1; i >= st; i--) {
        let pick = nums[i] + nex2
        let notPick = nex
        nex2 = nex
        nex = (pick < notPick) ? notPick : pick
    }
    
    return nex
};

var rob = (nums) => {
    const n = nums.length;
    if(n <= 2) return Math.max(...nums)
    
    let maxProf = Math.max(findProf(nums, 0, n-1), findProf(nums, 1, n))
    
    return maxProf;
}