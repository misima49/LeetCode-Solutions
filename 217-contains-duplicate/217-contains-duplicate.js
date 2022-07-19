/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let exist = new Set();
    let ans = 0;
    for(let itr of nums) {
        if(exist.has(itr)) ans++;
        else exist.add(itr);
    }
    
    return ans;
};