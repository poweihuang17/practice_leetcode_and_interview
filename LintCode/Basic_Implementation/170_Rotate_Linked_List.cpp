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
     * @param head: the List
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode * rotateRight(ListNode * head, int k) {
        // write your code here
        if(head==nullptr) return head;
        
        ListNode * count_ptr=head;
        int count=0;
        while(count_ptr!=nullptr)
        {
        	count++;
        	count_ptr=count_ptr->next;
        }
        k=k%count;
        if(k==0) return head;
        
        ListNode * right=head, * left=head;
        for(int i=0;i<k;i++)
        	right=right->next;
        while(right->next!=nullptr)
        {
        	right=right->next;
        	left=left->next;
        }
        
        ListNode * ret=left->next;
        left->next=nullptr;
        right->next=head;
        
        return ret;
    }
};