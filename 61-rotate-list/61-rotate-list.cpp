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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        
        ListNode* itr = head;
        int n = 1;
        while(itr->next) {
            n++;
            itr = itr->next;
        }
        cout << n;
        k = k%n;
        k = n-k;
        itr->next = head;
        itr = head;
        while(--k) itr = itr->next;
        head = itr->next;
        itr->next = NULL;
        
        return head;
    }
};