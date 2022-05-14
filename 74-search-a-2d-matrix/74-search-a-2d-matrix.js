/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    const m = matrix.length;
    const n = matrix[0].length;
    let start = 0, end = m*n-1;
    let mid = Math.round((end - start)/2);
    
    while(start <= end) {
        console.log(start + " " + end + " " + matrix[Math.trunc(mid/n)][Math.round(mid%n)]);
        if(matrix[Math.trunc(mid/n)][Math.round(mid%n)] == target) return true;
        
        if(matrix[Math.trunc(mid/n)][Math.round(mid%n)] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        
        mid = Math.round(start + (end-start)/2);
    }
    
    return false;
};