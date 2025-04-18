/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL && headB==NULL) return NULL;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        bool a=true;bool b=true;
        while(tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
            if(tempA==tempB) return tempA;
            if(tempA==NULL){
                tempA=headB;
            }
            else if(tempB==NULL){
                tempB=headA;
            }
        }
        return tempA;
        
    }
};