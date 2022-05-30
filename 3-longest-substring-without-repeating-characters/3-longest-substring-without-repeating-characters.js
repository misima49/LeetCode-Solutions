/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let maxSubStr = 0;
    let uniqMap = new Map();
    let i = 0, strStart = 0;
    
    for(i = 0, strStart = 0; i < s.length; i++) {
        if(!uniqMap.has(s[i])) {
            uniqMap.set(s[i], i);
        } else {
            maxSubStr = Math.max(i - strStart, maxSubStr);
            if(uniqMap.get(s[i]) < strStart) {
                uniqMap.set(s[i], i);
            } else {
                
                strStart = uniqMap.get(s[i]) + 1;
                uniqMap.set(s[i], i);
            }
        }
    }
    
    return Math.max(maxSubStr, i - strStart);
};