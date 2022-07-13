/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    let i = 0, j = 0;
    let sLen = s.length, tLen = t.length;
    while(i < sLen && j < tLen) {
        if(s[i] == t[j]) {
            i++; j++;
        } else {
            j++;
        }
    }
    
    if(i == sLen) return true;
    else return false;
};