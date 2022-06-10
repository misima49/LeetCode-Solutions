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
        ListNode* cur = head;
        
        while(cur) {
            if(cur->next && cur->val == cur->next->val) {
                while(cur->next && cur->val == cur->next->val) {
                    ListNode* temp = cur;
                    cur = cur->next;
                    delete temp;
                }
                
                prev->next = cur->next;
            } else {
                prev = prev->next;
            }
            
            cur = cur->next;
        }
        
        return dummy->next;
    }
};