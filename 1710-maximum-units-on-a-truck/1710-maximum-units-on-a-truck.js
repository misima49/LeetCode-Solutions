/**
 * @param {number[][]} boxTypes
 * @param {number} truckSize
 * @return {number}
 */
var maximumUnits = function(boxTypes, truckSize) {
    boxTypes.sort((a, b) => b[1] - a[1])
    let maxUnits = 0;
    for(let itr of boxTypes) {
        if(truckSize < itr[0]) {
            maxUnits += truckSize*itr[1]
            return maxUnits;
        }
        
        maxUnits += itr[0]*itr[1]
        truckSize -= itr[0]
    }
    
    return maxUnits
    
};