/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let st = 0, ed = s.length - 1;
    while(st < ed) {
        if(!((s[st].toLowerCase() >= 'a' && s[st].toLowerCase() <= 'z') || (s[st].toLowerCase() >= '0' && s[st].toLowerCase() <= '9'))) {
            st++;
            continue;
        }
        if(!((s[ed].toLowerCase() >= 'a' && s[ed].toLowerCase() <= 'z') || (s[ed].toLowerCase() >= '0' && s[ed].toLowerCase() <= '9'))) {
            ed--;
            continue;
        }
        
        if(s[st].toLowerCase() != s[ed].toLowerCase()) return false;
        st++; ed--;
    }
    
    return true;
};