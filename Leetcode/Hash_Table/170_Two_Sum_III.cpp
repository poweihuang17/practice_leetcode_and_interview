#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// TLE now....
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {   
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
    	if(nums.find(number) != nums.end())
    		hashTable[2*number]=true;
    	else
    	{
    		for(auto & num:nums)
    		{
    			hashTable[num+number]=true;
    		}
    		nums.insert(number);
    	}
       
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
    	return hashTable.count(value);
    }   
   
private:
	unordered_map<int, bool> hashTable;
	unordered_set<int> nums;
};

//Accepted O(N)
class TwoSum2 {
    unordered_map<int,int> map;
public:
    void add(int number) {
        map[number]++;
    }

    bool find(int number)
    {
    	for(auto & kv :map)
    	{
    		int j = number-kv.first;
    		if ( ( kv.first==j && map[j]>1) || (kv.first!=j && map.count(j) ) )
    			return true;
    	}
    	return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */

int main()
{
	TwoSum s=TwoSum();
	s.add(4);
	s.add(4);
	s.add(5);
	s.add(7);
	cout<<s.find(10)<<'\n';
	cout<<s.find(11)<<'\n';
}
