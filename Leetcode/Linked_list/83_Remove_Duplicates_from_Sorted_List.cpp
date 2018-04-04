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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return nullptr;
    	ListNode * top=head;
        while(head!=nullptr && head->next!=nullptr)
        {
        	if(head->val==head->next->val)
        	{
        		ListNode * temp=head->next;
        		head->next=head->next->next;
        		delete temp;
        		//head=head->next;
        	}
        	else
        		head=head->next;
        }
        return top;
    }
};