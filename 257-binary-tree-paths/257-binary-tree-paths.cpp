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
    void binaryTreePath(TreeNode* root, vector<string>& ans, string& curPath) {
        curPath.append(to_string(root->val));
        // cout << curPath << "\n";
        if(!root->right && !root->left) {
            ans.push_back(curPath);
        } else {
            curPath.append("->");
            if(root->right) {
                binaryTreePath(root->right, ans, curPath);
            }
            
            if(root->left) {
                binaryTreePath(root->left, ans, curPath);
            }
            curPath.pop_back();
            curPath.pop_back();
        }
        while(!curPath.empty() && curPath.back() != '>') curPath.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string curPath = "";
        // curPath.append(to_string(root->val));
        // cout << curPath;
        binaryTreePath(root, ans, curPath);
        return ans;
    }
};