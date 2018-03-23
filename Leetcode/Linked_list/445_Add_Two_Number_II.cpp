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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * t1=l1;
        ListNode * t2=l2;      
        vector<int> v1;
        v1.push_back(l1->val);       
        while(l1->next)
        {
            l1=l1->next;
            v1.push_back(l1->val);
        }  
        vector<int> v2;
        v2.push_back(l2->val);
        while(l2->next)
        {
            l2=l2->next;
            v2.push_back(l2->val);
        }
        
        int i=v1.size()-1;
        int j=v2.size()-1;
        int carry=0;
        vector<int> vsum;
        int sum=0;
        while(i>=0 || j>=0 || sum>0)
        {
            if(i>=0) sum+=v1[i--];
            if(j>=0) sum+=v2[j--];
            vsum.push_back(sum%10);
            sum=sum/10;
        }
        ListNode * p=new ListNode(vsum[vsum.size()-1]);
        ListNode * r=p;
        for(int k=vsum.size()-2;k>=0;k--)
        {
            ListNode * temp=new ListNode (vsum[k]);
            p->next=temp;
            p=temp;
            
        }
        
        return r;
        
    }
};