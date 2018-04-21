/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        // Write your code here
        unordered_map<int,priority_queue<double,vector<double>,greater<double>>> table;
        for(auto & result: results)
            {
                table[result.id].push(result.score);
                if(table[result.id].size()>5)
                    table[result.id].pop();
            }
        map<int,double> ret;
        for(auto & kv:table)
        {
            double average=0;
            while(kv.second.size())
                {
                    average+=kv.second.top();
                    kv.second.pop();
                }
            average/=5.0;
            ret[kv.first]=average;
        }
        return ret;
    }
};