/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        Node* newHead = new Node(head->val);
        Node* itrO = head;
        Node* itrN = newHead;
        
        unordered_map<Node*, Node*> hash;
        
        while(itrO->next) {
            hash[itrO] = itrN;
            itrO = itrO->next;
            itrN->next = new Node(itrO->val);
            itrN = itrN->next;
        }
        
        hash[itrO] = itrN;
        
        itrO = head;
        itrN = newHead;
        
        while(itrO) {
            if(itrO->random) {
                itrN->random = hash[itrO->random];
            }
            
            itrO = itrO->next;
            itrN = itrN->next;
        }
        
        return newHead;
    }
};