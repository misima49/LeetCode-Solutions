/**
 * // Definition for a Node.
 * function Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */

/**
 * @param {Node} root
 * @return {Node}
 */
var connect = function(root) {
    if(root === null) return root;
    let st = [];
    st.push(root);
    
    while(st.length > 0) {
        let n = st.length;
        // console.log(n);
        
        while(--n) {
            let cur = st[0];
            st.shift();
            if(cur.left) {
                st.push(cur.left);
                st.push(cur.right);
            }
            cur.next = st[0];
        }
        
        if(st[0].left) {
            st.push(st[0].left);
            st.push(st[0].right);
        }
        
        st.shift();
    }
    
    return root;
};