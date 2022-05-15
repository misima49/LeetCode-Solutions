/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let x = 0;
    let y = matrix[0].length - 1;
    
    while(x < matrix.length && y >= 0) {
        if(matrix[x][y] == target) return true;
        
        if(matrix[x][y] > target) {
            y--;
        } else {
            x++;
        }
    }
    
    return false;
};