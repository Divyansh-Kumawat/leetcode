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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return NULL;
        }
        
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
            
        }
        int rem=cnt-n;
        temp=head;
        ListNode* prev=NULL;
        if(rem==0){
            ListNode* first=head;
            head=head->next;
            delete first;
            return head;
        }
        while(rem--){
            prev=temp;
            temp=temp->next;
            
            
        }
        
        
            prev->next=prev->next->next;
        
        temp->next=nullptr;
        
        return head;
        
    }
};