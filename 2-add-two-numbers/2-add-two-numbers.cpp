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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curSum = new ListNode((l1 -> val + l2 -> val) % 10);
        int carry = (l1 -> val + l2 -> val) / 10;
        l1 = l1 -> next;
        l2 = l2 -> next;
        ListNode* result = curSum;
        
        while(l1 && l2) {
            curSum -> next = new ListNode((l1 -> val + l2 -> val + carry) % 10);
            carry = (l1 -> val + l2 -> val + carry) / 10;
            curSum = curSum -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        while(l1) {
            curSum -> next = new ListNode((l1 -> val + carry) % 10);
            carry = (l1 -> val + carry) / 10;
            curSum = curSum -> next;
            l1 = l1 -> next;
        }
        
        while(l2) {
            curSum -> next = new ListNode((l2 -> val + carry) % 10);
            carry = (l2 -> val + carry) / 10;
            curSum = curSum -> next;
            l2 = l2 -> next;
        }
        
        if(carry) {
            curSum -> next = new ListNode(carry);
        }
        
        return result;
    }
};