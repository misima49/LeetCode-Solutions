/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNode = function(head) {
    let count = 0;
    let itr = head;
    
    while(itr) {
        count++;
        itr = itr.next;
    }
    
    itr = head;
    count = Math.floor(count/2);
    // console.log(Math.floor(count));
    while(count > 0) {
        itr = itr.next;
        count--;
    }
    
    return itr;
};