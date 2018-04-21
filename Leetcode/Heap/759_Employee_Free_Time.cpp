/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> all;
        for(auto & s:schedule)
        {
            for(auto & s1:s)
                all.push_back(s1);
        }
        
        auto compare=[](const Interval & a, const Interval & b ){
          if(a.start<b.start)
              return true;
          else if (a.start==b.start && a.end>b.end)
              return true;
          else
              return false;
        };  
        
        sort(all.begin(),all.end(),compare);
        vector<Interval> merge;
        for(int i=0;i<all.size();)
        {
            int end=all[i].end;
            int start=all[i].start;
            int j=i+1;
            for(j=i+1;j<all.size() && end>=all[j].start;j++)
            {
                end=max(end,all[j].end);
            }
            merge.emplace_back(start,end);
            i=j;
        }
        vector<Interval> ret;
        for(int i=0;i<merge.size()-1;i++)
        {
            ret.emplace_back(merge[i].end,merge[i+1].start);
        }
        return ret;
    }
};