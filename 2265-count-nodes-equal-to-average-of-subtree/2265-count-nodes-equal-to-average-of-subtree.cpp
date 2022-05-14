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
    pair<int,int> dfs(TreeNode* root, int &result) {
        if(root == NULL) return {0, 0};
        
        pair<int, int> left(make_pair(0,0));
        pair<int, int> right(make_pair(0,0));
        
        if(root->left) {
            left = dfs(root->left, result);
        }
        if(root->right) {
            right = dfs(root->right, result);
        }
        int avg = (root->val + left.first + right.first)/(1 + left.second + right.second);
        if(avg == root -> val)  result++;
        return make_pair(root->val + left.first + right.first, 1 + left.second + right.second);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int answer = 0;
        dfs(root, answer);
        
        return answer;
    }
};