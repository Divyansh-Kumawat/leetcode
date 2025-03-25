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
    ListNode findNode(ListNode head,int n){
        int cnt=1;
        while(head.next!=null){
            if(cnt==n) return head;
            cnt++;
             head= head.next;
        }
        return  head;
    }
    public ListNode rotateRight(ListNode head, int k) {
        ListNode tail=head;
        if(head==null || head.next==null) return head;
        
        int n=1;
        while(tail.next!=null){
            tail=tail.next;
            n++;
        }
        if(k%n==0 ) return head;
        k=k%n;
        tail.next=head;
        ListNode newNode= findNode(head,n-k);
        head=newNode.next;
        newNode.next=null;
        return head;
    }
}