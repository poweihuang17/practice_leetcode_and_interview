/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return NULL;

        unordered_map<RandomListNode * , RandomListNode * > record;
        RandomListNode * p1= head;
        RandomListNode * p2= new RandomListNode(head->label);

        record[p1]=p2;

        queue<RandomListNode * > myqueue;

        myqueue.push(p1);

        while(!myqueue.empty())
        {
        	p1=myqueue.front();
        	p2=record[p1];
        	myqueue.pop();

        	if(p1->next && record.count(p1->next)==0)
        	{
        		RandomListNode * temp= new RandomListNode(p1->next->label);
        		record[p1->next]=temp;
        		p2->next=temp;
        		myqueue.push(p1->next);
        	}
        	else if (p1->next)
        	{
        		p2->next=record[p1->next];
        	}

        	if(p1->random && record.count(p1->random)==0)
        	{
        		RandomListNode * temp= new RandomListNode(p1->random->label);
        		record[p1->random]=temp;
        		p2->random=temp;
        		myqueue.push(p1->random);
        	}
        	else if (p1->random)
        	{
        		p2->random=record[p1->random];
        	}
        }

        return record[head]; 

    }
};