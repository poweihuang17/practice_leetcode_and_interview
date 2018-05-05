/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: The intervals
     * @return: The answer
     */
    int digitalCoverage(vector<Interval> &intervals) {
        // Write your code here
        map<double,int> c;
        for(auto & i:intervals)
        {
        	c[i.start]+=1;
        	c[i.end+0.1]-=1;
        }
        int m=0;
        int d=0;
        int ret=0;
        for(auto &kv:c)
        {
        	m+=kv.second;
        	//cout<<kv.first<<" "<<kv.second<<endl;
        	if(d<m)
        		{
        			ret=(int) kv.first;
        			d=m;
        			//cout<<d<<" "<<m<<" "<<"change"<<endl;
        		}
        }
        return ret;
    }
};