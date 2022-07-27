#pragma GCC optimize("O2")

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
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* cur = root;
        
       while(!st.empty()){
           cur = st.top();
           st.pop();
           
           if(cur -> right) {
               st.push(cur -> right);
           }
           if(cur -> left) {
               st.push(cur -> left);
           }
           cout << cur -> val << " ";
           if(!st.empty()) {
               cur -> right = st.top();
           }
           cur -> left = NULL;
       }
    }
};