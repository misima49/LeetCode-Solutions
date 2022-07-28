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
    bool isSymmetric(TreeNode* lh, TreeNode* rh) {
        if(!lh && !rh) return true;
        else if(!lh) return false;
        else if(!rh) return false;
        
        if(lh->val != rh->val) return false;
        if(!isSymmetric(lh->left, rh->right)) return false;
        if(!isSymmetric(lh->right, rh->left)) return false;
        
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        return isSymmetric(root->left, root->right);
    }
};