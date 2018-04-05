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
    ListNode* plusOne(ListNode* head) {
        int c=1;
        int diff=1;
        while(c!=0)
        {
        	ListNode * fast=head, *slow=head;
        	bool overflow=false;
        	for(int i=0;i<diff;i++)
        		if(fast!=nullptr)
        			fast=fast->next;
        		else
        			overflow=true;

        	if(overflow)
        	{
        		ListNode * new_head=new ListNode(1);
        		new_head->next=head;
        		return new_head;
        	}

        	while(fast!=nullptr)
        	{
        		fast=fast->next;
        		slow=slow->next;
        	}
        	slow->val+=1;
            c=0;
        	if(slow->val==10) {
        		slow->val=0;
        		c=1;
        		diff++;		
        	}
        }
        return head;	
    }
};