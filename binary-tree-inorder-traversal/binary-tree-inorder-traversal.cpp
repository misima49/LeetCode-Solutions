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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;
        
        while(1) {
            if(root) {
                st.push(root);
                root = root->left;
            } else {
                if(st.empty()) break;
                TreeNode* cur = st.top();
                st.pop();
                inorder.push_back(cur->val);
                
                root = cur->right;
            }
        }
        
        return inorder;
    }
};