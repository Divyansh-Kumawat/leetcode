/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
       if(head.next == null)return;
       ListNode slow = head, fast = head, prevSlow = slow;
        //get hold of mid of linked list
        while(fast != null &&  fast.next != null){
            prevSlow = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        prevSlow.next = null;
        ListNode firstHlfHead = head;
        ListNode secondHlfHead = reverse(slow);
        while(firstHlfHead != null && secondHlfHead != null){
            
            ListNode nextFirstHlfNode = firstHlfHead.next;
            firstHlfHead.next = secondHlfHead;
            firstHlfHead = nextFirstHlfNode;
            ListNode nextSecondHlfNode = secondHlfHead.next; 
            secondHlfHead.next = (nextFirstHlfNode != null) ? nextFirstHlfNode : nextSecondHlfNode;
            secondHlfHead = nextSecondHlfNode;
        }
    }
    private ListNode reverse(ListNode head){
        ListNode curr = head, prev = null;
        while(curr != null){
            ListNode nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
}