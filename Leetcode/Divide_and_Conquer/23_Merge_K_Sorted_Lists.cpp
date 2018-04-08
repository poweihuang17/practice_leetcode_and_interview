/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//C++ return reference
// I remember in the nested number or nested list problem. 
// There is an nested problem.
// But it return the variable inside the object
//Couldn't return a reference of variable from the function, right?
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        	return nullptr;
       	while(lists.size()>1)
       	{
       		lists.push_back(mergeTwoLists(lists[0],lists[1]));
       		lists.erase(lists.begin());
       		lists.erase(lists.begin());
       	}
       	return lists.front();
    }
    ListNode * mergeTwoLists(ListNode * & l1, ListNode * & l2)
    {
    	if(l1==nullptr)
    		return l2;
    	if(l2==nullptr)
    		return l1;
    	if(l1->val<=l2->val)
    	{
    		l1->next=mergeTwoLists(l1->next,l2);
    		return l1;
    	}
    	else
    	{
    		l2->next=mergeTwoLists(l1,l2->next);
    		return l2;
    	}
    }
};