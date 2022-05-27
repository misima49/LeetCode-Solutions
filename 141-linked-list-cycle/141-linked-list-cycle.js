/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    if(head == null) return false;
    
    let fast = head;
    let slow = head;
    
    while(fast && slow) {
        console.log(fast.val, slow.val);
        fast = fast.next;
        slow = slow.next;
        if(fast)
            fast = fast.next;
        else break;
        if(fast == slow) return true;
    }
    
    
    return false;
};