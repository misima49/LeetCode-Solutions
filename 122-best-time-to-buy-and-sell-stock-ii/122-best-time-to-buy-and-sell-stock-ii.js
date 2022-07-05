/**
 * @param {number[]} prices
 * @return {number}
 */

var maxProfit = function(prices) {
    const n = prices.length;
    let dp = new Array(n+1);
    for(let i = 0; i <= n; i++) {
        dp[i] = new Array(2);
        dp[i][0] = dp[i][1] = 0;
    } 

    for(let i = n-1; i >= 0; i--) {
        dp[i][0] = Math.max(dp[i+1][1]+prices[i], dp[i+1][0]);
        dp[i][1] = Math.max(dp[i+1][0]-prices[i], dp[i+1][1]);
    }
    
    return dp[0][1]
};