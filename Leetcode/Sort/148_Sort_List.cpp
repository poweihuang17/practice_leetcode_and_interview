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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode * fast=head;
        ListNode * slow=head;
        ListNode * prev=head;

        while(fast!=nullptr && fast->next!=nullptr)
        {
          fast=fast->next->next;
          prev=slow;
          slow=slow->next;
        }
        if(fast==slow) return head;
        prev->next=nullptr;

        ListNode * right=sortList(slow);
        ListNode * left=sortList(head);
        return mergelist(right,nullptr, left,nullptr);
    }
private:

   ListNode * mergelist(ListNode * rstart, ListNode * rend,ListNode * lstart,ListNode *lend)
   {
    if(lstart==nullptr) return rstart;
    else if(rstart==nullptr) return lstart;
    ListNode * aux=new ListNode(0);
    ListNode * temp=aux;

    while(rstart!=rend && lstart!=lend)
    {
      if(rstart->val <lstart->val)
      {
        aux->next=rstart;
        rstart=rstart->next;
        aux=aux->next;
      }
      else
      {
        aux->next=lstart;
        lstart=lstart->next;
        aux=aux->next;
      }
    }

    if(rstart!=rend)
      aux->next=rstart;
    if(lstart!=lend)
      aux->next=lstart;
    
    ListNode * ret=temp->next;
    delete temp;
    return ret;
   }

};