/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let minPrice = 1e8;
    let maxProfit = 0;
    
    for(let i = 0; i < prices.length; i++) {
        if(prices[i] < minPrice) 
            minPrice = prices[i];
        
        maxProfit = Math.max(maxProfit, prices[i] - minPrice);
    }
    
    return maxProfit;
};