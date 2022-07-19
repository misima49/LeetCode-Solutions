/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let exist = new Set();
    for(let itr of nums) {
        if(exist.has(itr)) return true;
        exist.add(itr);
    }
    
    return false;
};