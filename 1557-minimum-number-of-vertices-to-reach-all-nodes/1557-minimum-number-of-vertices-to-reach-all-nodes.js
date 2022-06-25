/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findSmallestSetOfVertices = function(n, edges) {
    let indeg = new Array(n); for(let i = 0; i < n; i++) indeg[i] = 0;
    
    for(edge of edges) {
        indeg[edge[1]]++;
    }
    let ans = [];
    for(let itr = 0; itr < n; itr++) {
        // console.log(indeg[itr])
        if(indeg[itr] == 0) ans.push(itr)
    }
    
    return ans;
};