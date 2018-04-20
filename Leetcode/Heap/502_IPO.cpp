class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
      priority_queue< pair<int,int> > maxheap;
      priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> minheap;
      int ret=W;
      
      for(int i=0;i<Profits.size();i++)
      	minheap.emplace(Capital[i],Profits[i]);
    
      while(1)
      {
      	while(!minheap.empty() && minheap.top().first<=ret)
      		{
                
      			maxheap.emplace(minheap.top().second,minheap.top().first);
      			minheap.pop();
      		}
      	if(!maxheap.empty() && k>0)
      	{
      		ret+=maxheap.top().first;
      		maxheap.pop();
      		k--;
      	}
      	else
      		return ret;
      }
       
      return ret;
    }
};