class Solution {
public:
    string nextClosestTime(string time) {
        
    }

private:

	void dfs(int dep,const vector<int> )

	int toTime(int h, int m){
		return h*60+m;
	}

	int timeDiff(int t1, int t2){
		//Why?
		if(t1==t2) return INT_MAX

		return ((t2-t1)+24*60)%(24*60)
	}
};