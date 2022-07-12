/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    let ver1 = version1.split('.');
    let ver2 = version2.split('.');
    let n1 = ver1.length
    let n2 = ver2.length;
    
    let i = 0, j = 0;
    for( ; i < n1 || j < n2; i++, j++) {
        let rev1 = 0, rev2 = 0;
        if(i < n1) rev1 = +ver1[i];
        if(j < n2) rev2 = +ver2[j];
        
        if(rev1 == rev2) continue;
        if(rev1 < rev2) return -1;
        else return 1;
    }
    
    return 0;
};