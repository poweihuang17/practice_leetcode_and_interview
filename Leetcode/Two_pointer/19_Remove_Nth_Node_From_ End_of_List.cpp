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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode * first=head;
       ListNode * second=head;
       ListNode * ans;
        
       for(int i=0;i<n;i++)
       {
       	first=first->next;
       }
       
       if(first==NULL)
       {
           ans=head->next;
           delete second;
           return ans;
       }
        
       
       while(first->next !=NULL)
       {
       	first=first->next;
       	second=second->next;
       }
       
       ListNode * temp=second->next->next;
       delete second->next;
       second->next=temp;
       return head;

    }
};