/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    if(n == 0) return 0
    if(n <= 2) return 1
    let prev = 1
    let prev2 = 1
    n -= 2
    let cur;
    while(n--) {
        cur = prev + prev2
        prev2 = prev
        prev = cur
    }
    
    return cur
};