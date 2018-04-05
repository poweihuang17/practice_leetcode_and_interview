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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
    	int size=0;
    	ListNode * count=root;
    	while(count!=nullptr)
    	{
    		size++;
    		count=count->next;
    	}
    	int m=size/k;
    	int n=size%k;
    	
    	vector<ListNode *> ret(k,nullptr);

    	ListNode * prev=new ListNode(0);
        ListNode * head=root;
    	prev->next=head;
    	ListNode * next=head;
        root=prev;
        
    	for(int i=0;i<n;i++)
    	{
    		ret[i]=head;
            prev=root;
    		for(int j=0;j<m+1;j++)
    		{
    			prev=prev->next;
    			head=head->next;
    		}
    		prev->next=nullptr;
            root->next=head;
    	}

    	for(int i=n;i<k;i++)
    	{
    		ret[i]=head;
            prev=root;
    		for(int j=0;j<m;j++)
    		{
    			prev=prev->next;
    			head=head->next;
    		}
    		prev->next=nullptr;
            root->next=head;
    	}
        return ret;
    }
};