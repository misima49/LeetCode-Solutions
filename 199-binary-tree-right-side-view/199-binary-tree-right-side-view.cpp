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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if(!root) return rightView;
        stack<pair<TreeNode*, int>> st;
        st.emplace(root, 0);
        
        while(!st.empty()) {
            TreeNode* cur = st.top().first;
            int curlvl = st.top().second;
            st.pop();
            
            if(rightView.size() <= curlvl) rightView.push_back(cur->val);
            if(cur->left) st.emplace(cur->left, curlvl+1);
            if(cur->right) st.emplace(cur->right, curlvl+1);
        }
        
        return rightView;
    }
};