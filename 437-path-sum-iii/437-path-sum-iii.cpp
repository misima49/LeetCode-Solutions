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
typedef long long ll;
class Solution {
    void findSum(TreeNode* root, ll targetSum, int& ans) {
        if(!root) return;
        if(targetSum == root->val) {
            ans++;
        } 
        
        findSum(root->left, targetSum - root->val, ans);
        findSum(root->right, targetSum - root->val, ans);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        if(root) {
            findSum(root, targetSum, ans);
            ans += pathSum(root->left, targetSum);
            ans += pathSum(root->right, targetSum);
            return ans;
        } else {
            return 0;
        }
    }
};