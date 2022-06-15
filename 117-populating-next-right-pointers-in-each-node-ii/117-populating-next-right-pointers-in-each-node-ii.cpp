/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        Node* itr = root;
        Node* nextLevel = NULL;
        bool flag = true;
        
        while(itr) {
            cout << itr->val << " ";
            
            if(flag == true) {
                Node* temp = itr;
                while(temp && (!(temp->left) && !(temp->right))) {
                    temp = temp->next;
                }
                
                if(temp) {
                    if(temp->left) 
                        nextLevel = temp->left;
                    else
                        nextLevel = temp->right;
                } else
                    nextLevel = NULL;
                
                flag = false;
            }

            if(itr->left) {
                if(itr->right) {
                    itr->left->next = itr->right;
                } else if(itr->next) {
                    Node* temp = itr->next;
                    while(temp && (!(temp->left) && !(temp->right))) {
                        temp = temp->next;
                    }
                    if(temp) {
                        if(temp->left) 
                            itr->left->next = temp->left;
                        else
                            itr->left->next = temp->right;
                    }
                }
            }
            
            if(itr->right) {
                if(itr->next) {
                    Node* temp = itr->next;
                    while(temp && (!(temp->left) && !(temp->right))) {
                        temp = temp->next;
                    }
                    if(temp) {
                        if(temp->left) 
                            itr->right->next = temp->left;
                        else
                            itr->right->next = temp->right;
                    }
                }
            }
            
            if(itr->next)
                itr = itr->next;
            else {
                itr = nextLevel;
                flag = true;
            }
        }
        
        return root;
    }
};