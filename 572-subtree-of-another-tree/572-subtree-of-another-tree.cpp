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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        
        // cout << root->val << " " << subRoot->val << "\n";
        if(isSameTree(root, subRoot))
            return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL || t2 == NULL) 
            return t1 == NULL && t2 == NULL;
        
        if(t1->val == t2->val) 
            return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
        else 
            return false;
    }
};