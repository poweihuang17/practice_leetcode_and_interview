#include <vector>
#include <iostream>
using namespace std;


//How to construct a nested integer class?


  // This is the interface that allows for creating nested lists.
  // You should not implement it, or speculate about its implementation
  class NestedInteger {
    public:
      // Constructor initializes an empty nested list.
      NestedInteger();
 
      // Constructor initializes a single integer.
      NestedInteger(int value);
 
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Set this NestedInteger to hold a single integer.
      void setInteger(int value);
 
      // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      void add(const NestedInteger &ni);
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
  };

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        if(nestedList.size()==0) return 0;
        int depth=0;
        helper(nestedList,depth);
        int sum=0;
        for(int i=record.size()-1,l=1;i>=0;i--,l++)
        	sum+=record[i]*l;
        return sum;
    }

    void helper(vector<NestedInteger>& nestedList, int depth)
    {
    	if(depth+1>record.size()) record.resize(depth+1);

    	for(auto & nested:nestedList)
    	{
    		if(nested.isInteger())
    			record[depth]+=nested.getInteger();
    		
    		else
    			helper(nested.getList(),depth+1);
    	}
    }

private:
	vector<int> record;
};

int main(){
	Solution s;
	NestedInteger n(-1);
	n.add(NestedInteger(-1));
	vector<NestedInteger>  nestedList{n};
	cout<<s.depthSumInverse(nestedList);
}
