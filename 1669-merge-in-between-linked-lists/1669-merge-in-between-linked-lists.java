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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode temp1 = list1;
        ListNode temp2 = list2;
        Queue<Integer> q1 = new LinkedList<>();
        int num = 0;

        while(temp1!=null)
        {
            while(num>=a && num<=b)
            {
                num++;
                temp1=temp1.next;
                continue;
            }
            q1.add(temp1.val);
            temp1=temp1.next;
            num++;
        }
        // System.out.print(q1);
        num=0;
        ListNode ans = new ListNode(-1);
        ListNode temp3 = ans;

        while(!q1.isEmpty())
        {
            if(num==a)
            {
                while(temp2!=null)
                {
                    temp3.next=temp2;
                    temp3=temp2;
                    temp2=temp2.next;
                }
            }
            ListNode z = new ListNode(q1.poll());
            temp3.next=z;
            temp3=z;
            num++;
        }

        return ans.next;
    }
}