/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if(!node) return NULL;
    	UndirectedGraphNode * p1 = node;
    	UndirectedGraphNode * p2= new UndirectedGraphNode(node->label);

    	unordered_map < UndirectedGraphNode * , UndirectedGraphNode *> record;
    	queue<UndirectedGraphNode * > myqueue;

    	myqueue.push(node);
    	record[node]=p2;

    	while(!myqueue.empty())
    		{
    			p1=myqueue.front();
    			p2=record[p1];

    			myqueue.pop();
    			for(auto neighbor: p1->neighbors)
    				{

		    			if(record.count(neighbor)==0)
		    			{
		    				UndirectedGraphNode * new_node=new UndirectedGraphNode(neighbor->label);
		    				p2->neighbors.push_back(new_node);
		    				record[neighbor]=new_node;
		    				myqueue.push(neighbor);
		    			}
		    			else
		    			{
		    				p2->neighbors.push_back(record[neighbor]);
		    			}
    				}
    		} 
    	return record[node];
        
    }
};