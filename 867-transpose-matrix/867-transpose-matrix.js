/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var transpose = function(matrix) {
    let m = matrix.length;
    let n = matrix[0].length;
    
    let transMat = new Array(n).fill().map(() => Array(m));
    
    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n; j++) {
            transMat[j][i] = matrix[i][j];
        }
    }
    return transMat;
};