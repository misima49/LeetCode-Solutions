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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        stack<TreeNode*> st;
        
        while(root || !st.empty()) {
            if(root) {
                st.push(root);
                root = root->left;
            } else {
                TreeNode* cur = st.top()->right;
                if(cur) {
                    root = cur;
                } else {
                    cur = st.top();
                    st.pop();
                    postorder.push_back(cur->val);
                    while(!st.empty() && cur == st.top()->right) {
                        cur = st.top();
                        st.pop();
                        postorder.push_back(cur->val);
                    }
                }
            }
        }
        
        return postorder;
    }
};