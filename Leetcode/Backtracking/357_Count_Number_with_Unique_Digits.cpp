class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n>10)
        	return countNumbersWithUniqueDigits(10);

    	int count=1;
    	long max=(long) pow(10,n);

    	vector<bool> visited(10,false);

        for(int i=1;i<10;i++)
        {
            visited[i]=true;
            backtrack(visited,i, max,count);
            visited[i]=false;
        }
        
        return count;
    }

    void backtrack(vector<bool> & visited, int number, int max, int  & count)
    {
    	if(number<max)
    		count++;
    	else
    		return;

    	for(int i=0;i<10;i++)
    	{
    		if(visited[i]==true) continue;
    		visited[i]=true;
    		backtrack(visited,number*10+i,max, count);
    		visited[i]=false;
    	}
    }
};

// This problem also has DP and Math solution, beside the backtracking solution.
// Need to learn 2 or 3 solutions for each problem.