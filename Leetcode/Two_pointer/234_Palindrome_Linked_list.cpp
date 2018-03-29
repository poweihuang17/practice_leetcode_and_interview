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
bool isPalindrome(ListNode* head) {
if (head==nullptr) return true;
ListNode* fast=head, * slow=head;
while(fast->next && fast->next->next){
fast=fast->next->next;
slow=slow->next;
}
slow=reverselist(slow->next);
while(slow)
    {
if(slow->val !=head->val)
return false;
slow=slow->next;
head=head->next;
}
return true;
}
private:
ListNode * reverselist(ListNode * A)
{
ListNode * pre=nullptr,* next=nullptr,* head=A;
while(head!=nullptr){
next=head->next;
head->next=pre;
pre=head;
head=next;
}
return pre;
}
};