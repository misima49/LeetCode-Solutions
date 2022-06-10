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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* dummy = new ListNode(head->val-1, head);
        ListNode* prev = dummy;
        ListNode* nex = prev->next;
        
        while(nex) {
            if(nex->val == prev->val) {
                prev->next = nex->next;
                nex = nex->next;
            } else {
                prev = prev->next;
                nex = nex->next;
            }
        }
        
        return dummy->next;
    }
};