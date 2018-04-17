/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    auto compare=[](const Interval & C, const Interval & D)
    {
    	return C.start<D.start || (C.start==D.start && C.end<D.end);
    };

    sort(A.begin(),A.end(),compare);
    vector<Interval> ret;
    for(int i=0;i<A.size();)
    {
    	int start=A[i].start;
    	int end=A[i].end;
    	i++;
    	while(i<A.size())
    	{
    		if(end>=A[i].start)
    			{
    			end=max(end,A[i].end);
    		    i++;
    			}
    		else
    		    break;
    	}
    	ret.push_back(Interval(start,end));
    }
    return ret;
}
