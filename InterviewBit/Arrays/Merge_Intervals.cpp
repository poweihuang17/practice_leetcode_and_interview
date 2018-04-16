#include <vector>
#include <algorithm>
using namespace std;

//  Definition for an interval.
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
 
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(newInterval.end<newInterval.start)
   		swap(newInterval.end,newInterval.start);
   
	auto it=upper_bound(intervals.begin(),intervals.end(),newInterval,[](const Interval & a, const Interval & b){
			return a.start<b.start || (a.start==b.start && a.end<b.end);});

	intervals.insert( it,newInterval);
	    
	vector<Interval> ret;
	for(int i=0;i<intervals.size();)
	{
		int start=intervals[i].start;
		int end=intervals[i].end;
		i++;
		while(i<intervals.size())
		{
			if(end>=intervals[i].start)
				{
					end=max(intervals[i].end,end);
					i++;
				}
			else
				break;
		}
		ret.push_back(Interval(start,end));
	}
	return ret;

}
