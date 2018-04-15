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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        dummy->next=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode * curr=dummy->next;
        int count=0, result=0;
        while(curr!=nullptr)
        {
        	count++;
        	if(rand()%count==0) result=curr->val;
        	curr=curr->next;
        }
        return result;
    }

private:
	ListNode * dummy=new ListNode(0);
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */