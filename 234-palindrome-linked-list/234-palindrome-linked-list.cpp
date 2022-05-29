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
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        
        ListNode* itr = head;
        while(itr) {
            vec.push_back(itr->val);
            itr = itr->next;
        }
        
        int start = 0, end = vec.size()-1;
        while(start < end) {
            if(vec[start++] != vec[end--]) return false;
        }
        
        return true;
    }
};