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
    ListNode reverseLinkedList(ListNode head){
        ListNode curr=head;
        ListNode next=null;
        ListNode prev=null;
        while(curr!=null){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode findkth(ListNode temp,int k){
        k=k-1;
        while(temp!=null && k>0){
            k--;
            temp=temp.next;
        }
        return temp;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head==null || head.next==null) return head;
        ListNode temp=head;
        ListNode prevNode=null;
        while(temp!=null){
            ListNode kth= findkth(temp,k);
            if(kth==null){
                if(prevNode!=null){
                    prevNode.next=temp;
                    break;
                }
            }
            ListNode nextNode=kth.next;
            kth.next=null;
            reverseLinkedList(temp);
            if(temp==head){
                head=kth;
            }else{
                prevNode.next=kth;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
}