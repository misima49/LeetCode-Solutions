/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var backspaceCompare = function(s, t) {
    let i = s.length, j = t.length;
    let sErase = 0, tErase = 0;
    
    while(i >= 0 || j >= 0) {
        while(i >= 0) {
            if(s[i] == '#') {
                i--;
                sErase++;
            } else if(sErase) {
                i--;
                sErase--;
            } else 
                break;
        }
        
        while(j >= 0) {
            if(t[j] == '#') {
                j--;
                tErase++;
            } else if(tErase) {
                j--;
                tErase--;
            } else 
                break;
        }
        
        if(i >= 0 && j >= 0 && s[i] != t[j]) return false;
        
        if((i >= 0) != (j >= 0)) return false;
        
        i--; j--;
    }
    
    return true;
};