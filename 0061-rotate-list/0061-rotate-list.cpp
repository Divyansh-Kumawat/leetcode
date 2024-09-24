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
    ListNode* findNode(ListNode* temp,int n){
        int cnt=1;
        while(temp->next!=NULL){
            if(cnt==n) return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (k==0 || head==NULL){
            return head;
        }
        
        int len=1;
        ListNode* tail=head;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        if(k%len==0) return head;
        k=k%len;
        tail->next=head;
        ListNode* newNode=findNode(head,len-k);
        head=newNode->next;
        newNode->next=NULL;
        return head;
    }
};