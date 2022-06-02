/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let left = 0;
    let right = height.length - 1;
    let leftmax = height[0]; 
    let rightmax = height[right];
    let ans = 0;
    
    while(left < right) {
        if(height[left] < height[right]) {
            left++;
            if(height[left] < leftmax) {
                ans += leftmax - height[left];
            } else {
                leftmax = height[left];
            }
        } else {
            right--;
            if(height[right] < rightmax) {
                ans += rightmax - height[right];
            } else {
                rightmax = height[right];
            }
        }
    }
    
    return ans;
};