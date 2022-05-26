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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dumb = new ListNode(-1, head);
        ListNode* itr = dumb;
        ListNode* nBehind = dumb;
        int count = 0;
        
        for(int i = 1; i <= n; i++) {
            itr = itr->next;
        }
        
        while(itr->next) {
            itr = itr->next;
            nBehind = nBehind->next;
        }
        nBehind -> next = nBehind->next->next;
        
        
        return dumb->next;
    }
};