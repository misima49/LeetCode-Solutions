/**
 * @param {string} n
 * @return {number}
 */
var minPartitions = function(n) {
    let largestDig = n[0]
    for(ch of n) {
        if(ch > largestDig) largestDig = ch
        if(largestDig === '9') return largestDig
    }
    return largestDig
};