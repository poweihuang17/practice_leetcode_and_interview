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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * t1=l1;
        ListNode * t2=l2;      
        int sum=0;
        ListNode * fake_head=new ListNode (0);
        ListNode * r=fake_head;

        while(t1 || t2 || sum)
        {
        	if(t1) {
                sum+=t1->val;
                t1=t1->next;
            }
        	if(t2) {
                sum+=t2->val;
                t2=t2->next;
            }
        	ListNode * p = new ListNode(sum%10);
        	fake_head->next=p;
        	sum=sum/10;
        	fake_head=p;
            
        }
        return r->next;
    }
};