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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* mid=head;
        int cnt=0;
        while(temp->next!= NULL){
            cnt++;
            temp=temp->next;
        }
        
        int m=0;
        if(cnt%2==0){
            m=(cnt/2);
        }
        else{
            m=cnt/2 +1;
        }
        while(m){
            mid=mid->next;
            m--;
        }
        return mid;
        
        
        
    }
};