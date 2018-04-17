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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> arrive;
        vector<int> depart;
        for(auto & i: intervals)
        {
            arrive.push_back(i.start);
            depart.push_back(i.end);
        }
        
        sort(arrive.begin(),arrive.end());
        sort(depart.begin(),depart.end());
        int count=0;
        int i=0,j=0;
        int ret=0;

        while(i<arrive.size() && j<depart.size())
        {
            if(arrive[i]<depart[j])
                {
                    count++;
                    ret=max(ret,count);
                    i++;
                }
            else //if(arrive[i]>depart[j])
            {
                count--;
                j++;
            }
        }
        return ret;
    }
};