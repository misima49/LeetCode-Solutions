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
    TreeNode* ans;
    void dfs(TreeNode* root, int k, int &cur) {
        // int lh = 0, rh = 0;
        // cout << root->val << " " << cur << "\n";
        
        if(root->left)dfs(root->left, k, cur);
        cur++;
        if(ans) return;
        if(cur == k) {
            ans = root;
            // cout << "Ans = " << root->val << "\n";
            return;
        }
        if(root->right) dfs(root->right, k, cur);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        int cur = 0;
        dfs(root, k, cur);
        return ans->val;
    }
};