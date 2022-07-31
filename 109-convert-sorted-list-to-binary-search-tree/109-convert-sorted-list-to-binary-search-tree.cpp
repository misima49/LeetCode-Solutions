/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    unordered_map<TreeNode*, int> heights;
    
    int height(TreeNode* node) {
        if(!node) return -1;
        return heights[node];
    }
    
    TreeNode* rightRotate(TreeNode* y) {
        // cout << "Right called";
        TreeNode* x = y->left;
        TreeNode* xR = x->right;
        
        x->right = y;
        y->left = xR;
        
        heights[y] = 1 + max(height(y->left), height(y->right));
        heights[x] = 1 + max(height(x->left), height(x->right));
        
        // cout << x->left->val << " " << x->right->val << '\n';
        return x;
    }
    
    TreeNode* leftRotate(TreeNode* y) {
        // cout << "Left called ";
        TreeNode* x = y->right;
        TreeNode* xL = x->left;
        
        x->left =  y;
        y->right = xL;
        
        heights[y] = 1 + max(height(y->left), height(y->right));
        heights[x] = 1 + max(height(x->left), height(x->right));
        
        // cout << x->val << " " << x->right->val << '\n';
        return x;
    }
    
    int getBalance(TreeNode* node) {
        return height(node->left) - height(node->right);
    }
    
    TreeNode* insert(int key, TreeNode* node) {
        if(!node) {
            TreeNode* ans = new TreeNode(key);
            heights[ans] = 0;
            return ans;
        }
        
        if(key < node->val) {
            node->left = insert(key, node->left);
        }
        else
        if(key > node->val) {
            node->right = insert(key, node->right);
        } else
            return node;
        
        heights[node] = 1 + max(height(node->left), height(node->right));
        
        int balance = getBalance(node);
        // cout << key << " " << balance << '\n';
        if(balance > 1 && key < node->left->val) {
            node = rightRotate(node);
            return node;
        } else if(balance < -1 && key > node->right->val) {
            node = leftRotate(node);
        } else if(balance > 1 && key > node->left->val) {
            node = leftRotate(node->left);
            node = rightRotate(node);
        } else if(balance < -1 && key < node->right->val) {
            node = rightRotate(node->right);
            node = leftRotate(node);
        }
        // cout << node->val << '\n';
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        TreeNode* root = NULL;
        ListNode* itr = head;
        
        while(itr) {
            root = insert(itr->val, root);
            // cout << root->val;
            itr = itr->next;
        }
        
        return root;
    }
};