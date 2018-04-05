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
    ListNode* oddEvenList(ListNode* head) {
    	
    	if(head==nullptr) return nullptr;

        ListNode * odd=head, * even=head->next, * even_head=even;

        while(even!=nullptr && even->next!=nullptr)
        {
        	odd->next=odd->next->next;
        	even->next=even->next->next;
        	odd=odd->next;
        	even=even->next;
        }
        odd->next=even_head;
        
        return head;
    }
};