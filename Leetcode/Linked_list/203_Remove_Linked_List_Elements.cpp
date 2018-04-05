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
    ListNode* removeElements(ListNode* head, int val) {
    	if(head==nullptr) return nullptr;
    	ListNode * pre=new ListNode(0);
    	pre->next=head;

    	ListNode * current=pre;
        ListNode * last;
    	while(pre!=nullptr && pre->next!=nullptr)
    	{
    		if(pre->next->val==val)
    		{
    			ListNode * temp=pre->next;
    			pre->next=pre->next->next;
    			delete temp;
    		}
            else
                pre=pre->next;
    	}

        
    	ListNode * ret=current->next;
    	delete current;

        return ret;
    }
};