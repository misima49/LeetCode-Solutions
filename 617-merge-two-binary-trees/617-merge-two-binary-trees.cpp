/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        
        stack<pair<TreeNode*, TreeNode*>> st;
        stack<TreeNode*> mergedSt;
        TreeNode* mergedTree = new TreeNode(root1 -> val + root2 -> val);
        TreeNode* itr = mergedTree;
        
        st.push({root1, root2});
        mergedSt.push(itr);
        
        while(!st.empty()) {
            root1 = st.top().first;
            root2 = st.top().second;
            itr = mergedSt.top();
            st.pop();
            mergedSt.pop();
            
            if(root1 && root2 && root1 -> left && root2 -> left) {
                itr -> left = new TreeNode(root1 -> left -> val + root2 -> left -> val);
                st.push({root1 -> left, root2 -> left});
                mergedSt.push(itr -> left);
            } else if(root1 && root1 -> left) {
                itr -> left = new TreeNode(root1 -> left -> val);
                st.push({root1 -> left, NULL});
                mergedSt.push(itr -> left);
            } else if(root2 && root2 -> left) {
                itr -> left = new TreeNode(root2 -> left -> val);
                st.push({NULL, root2 -> left});
                mergedSt.push(itr -> left);
            }
            
            if(root1 && root2 && root1 -> right && root2 -> right) {
                itr -> right = new TreeNode(root1 -> right -> val + root2 -> right -> val);
                st.push({root1 -> right, root2 -> right});
                mergedSt.push(itr -> right);
            } else if(root1 && root1 -> right) {
                itr -> right = new TreeNode(root1 -> right -> val);
                st.push({root1 -> right, NULL});
                mergedSt.push(itr -> right);
            } else if(root2 && root2 -> right) {
                itr -> right = new TreeNode(root2 -> right -> val);
                st.push({NULL, root2 -> right});
                mergedSt.push(itr -> right);
            }
        }
        
        return mergedTree;
    }
};