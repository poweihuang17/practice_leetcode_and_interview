/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

void printnode(ListNode * head)
{
	while(head!=nullptr)
	{
		cout<<head->val<<'\n';
		head=head->next;
	}
}
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    if(head==nullptr) return nullptr;
    int count=0;
    ListNode * res=head;
    ListNode * prev=nullptr;
  	while(head && head->next)
  	{ 
  		if(count==0) res=head->next;
  		count++;

  		ListNode * t=head->next->next;

  		if(prev!=nullptr) prev->next=head->next;
  		prev=head;

  		head->next->next=head;
  		head->next=t;

  		head=t;
  		//printnode(res);
  		//break;
  	}
  	if(prev!=nullptr) prev->next=head;
  	//printnode(res);
  	      
  	return res;
    }
};

int main()
{
	ListNode  * p1=new ListNode(1);
	ListNode * p2=new ListNode(2);
	ListNode * p3=new ListNode(3);
	ListNode * p4=new ListNode(4);
	//p1->next=p2;
	//p2->next=p3;
	//p3->next=p4;
	//ListNode * head=p1;
	//printnode(head);
	Solution().swapPairs(p1);
	//printnode(p1);

}

