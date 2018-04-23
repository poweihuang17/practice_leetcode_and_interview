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
    int numComponents(ListNode* head, vector<int>& G) {
        if(head==nullptr) return 0;
        multiset<int> s(G.begin(),G.end());
        int count=0;
        bool start=true;
        while(head!=nullptr)
        {
            auto it=find(s.begin(),s.end(),head->val);
            if(it!=s.end())
            {
                head=head->next;
                s.erase(it);
                if(start)
                {
                    count++;
                    start=false;
                }
                
                
            }
            else
            {
                if(start)
                    head=head->next;
                else
                    start=true;
            }
        }
        return count;
    }
};