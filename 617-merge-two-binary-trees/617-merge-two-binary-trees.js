/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {TreeNode}
 */
var mergeTrees = function(root1, root2) {
    if(!root1) return root2;
    if(!root2) return root1;
    
    let st1 = [];
    let st2 = [];
    
    st1.push(root1);
    st2.push(root2);
    
    while(st1.length > 0 && st2.length > 0) {
        let cur1 = st1[st1.length-1];
        let cur2 = st2[st2.length-1];
        
        // console.log(cur1.val, cur2.val);
        st1.pop();
        st2.pop();
        
        if(cur1 && cur2) {
            cur1.val += cur2.val;
        }
        
        if(cur1.left && cur2.left) {
            st1.push(cur1.left);
            st2.push(cur2.left);
        } else if(cur2.left) {
            cur1.left = new TreeNode(0);
            st1.push(cur1.left);
            st2.push(cur2.left);
        } else if(cur1.left) {
            cur2.left = new TreeNode(0);
            st1.push(cur1.left);
            st2.push(cur2.left);
        }
        
        if(cur1.right && cur2.right) {
            st1.push(cur1.right);
            st2.push(cur2.right);
        } else if(cur2.right) {
            cur1.right = new TreeNode(0);
            st1.push(cur1.right);
            st2.push(cur2.right);
        } else if(cur1.right) {
            cur2.right = new TreeNode(0);
            st1.push(cur1.right);
            st2.push(cur2.right);
        }
    }
    
    return root1;
};