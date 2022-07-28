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
    bool findHasPathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return targetSum == 0;
        }
        bool lh = false, rh = false;
        if(root->left) lh = hasPathSum(root->left, targetSum - root->val);
        if(root->right) rh = hasPathSum(root->right, targetSum - root->val);
        // cout << root->val << " " << lh << " " << rh << "\n";
        if(!root->left && !root->right) return targetSum == root->val;
        
        return lh || rh;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        return findHasPathSum(root, targetSum);
    }
};