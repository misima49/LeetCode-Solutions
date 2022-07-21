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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left == right) return head;
        ListNode* dummy = new ListNode(-1000, head);
        ListNode* itr = dummy;
        int pos = 0;
        while(pos < left-1) {
            itr = itr->next;
            pos++;
        }
        ListNode* start = itr;
        itr = itr->next;
        ListNode* prev = itr;
        itr = itr->next;
        ListNode* nex = itr->next;
        
        while(itr && pos < right-1) {
            nex = itr->next;
            pos++;
            itr->next = prev;
            prev = itr;
            itr = nex;
        }
        
        start->next->next = nex;
        start->next = prev;
        // cout << start->next->next->next->val;
        
        return dummy->next;
    }
};