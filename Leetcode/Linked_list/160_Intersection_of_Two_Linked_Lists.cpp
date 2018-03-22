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
        int count1=0;
        ListNode * temp1=headA;
        ListNode * temp2=headB;
        int count2=0;
        while(temp1)
        {
        	count1++;
        	temp1=temp1->next;
        }
        while(temp2)
        {
        	count2++;
        	temp2=temp2->next;
        }
        if(count2>count1)
        	for(int i=0;i<count2-count1;i++)
        		headB=headB->next;
        else
        	for(int i=0;i<count1-count2;i++)
        		headA=headA->next;

        while(headA!=headB)
        {
        	headA=headA->next;
        	headB=headB->next;
        }
        return headA;

    }
};