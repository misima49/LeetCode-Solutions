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
#define MONITERED 0
#define CAM_ADDED 1
#define CAM_NEEDED 2

class Solution {
    int camCount = 0;
public:
    int minCameraCover(TreeNode* root) {
        if(dfs(root) == CAM_NEEDED) camCount++;
        
        return camCount;
    }
private:
    int dfs(TreeNode* cur) {
        if(cur == NULL) return MONITERED;
        
        int left = dfs(cur->left);
        int right = dfs(cur->right);
        
        if(left == CAM_NEEDED || right == CAM_NEEDED) {
            camCount++;
            return CAM_ADDED;
        } else if(left == CAM_ADDED || right == CAM_ADDED)
            return MONITERED;
        else 
            return CAM_NEEDED;
    }
};