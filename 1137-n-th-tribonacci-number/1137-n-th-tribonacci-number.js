/**
 * @param {number} n
 * @return {number}
 */
var tribonacci = function(n) {
    if(n == 0) return 0
    if(n <= 2) return 1
    
    let p0 = 0, p1 = 1, p2 = 1
    n -= 2
    let ans;
    while(n--) {
        ans = p0 + p1 + p2
        p0 = p1
        p1 = p2
        p2 = ans        
    }
    
    return ans
};