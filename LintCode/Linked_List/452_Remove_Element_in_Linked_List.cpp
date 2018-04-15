/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: a ListNode
     * @param val: An integer
     * @return: a ListNode
     */
    ListNode * removeElements(ListNode * head, int val) {
        if(head==nullptr) return nullptr;
        // write your code here
        ListNode * prev=new ListNode(0);
        prev->next=head;
        ListNode * t=prev;
        while(t!=nullptr)
        {
        	while(t->next && t->next->val==val)
        	{
        		ListNode * temp=t->next;
        		t->next=temp->next;
        		delete temp;
        	}
        	t=t->next;
        }
        t=prev->next;
        delete prev;
        return t;
    }
};