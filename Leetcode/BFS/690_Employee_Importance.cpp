/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map < int, vector<int> > relation;
        unordered_map <int, int> importance;
        for( auto & employee :employees)
        {
            relation[employee->id]=employee->subordinates;
            importance[employee->id]=employee->importance;
        }

        queue<int> all;
        all.push(id);
        int sum=0;

        while (! all.empty())
        {

        	int i=all.front();
        	all.pop();
        	sum+=importance[i];
        	for (auto  & sub: relation[i])
        	{
        		all.push(sub);
        	}
        }
        return sum;
    }
};