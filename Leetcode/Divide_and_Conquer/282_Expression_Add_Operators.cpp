class Solution {
public:
	void dfs(int pos,string str,long long sum, long long last)
	{
		if(pos==num.size())
		{
			if(sum==target)
				ans.push_back(str);
			return;
		}

		for(int i=pos;i<num.size();i++)
		{
			string curNumS=num.substr(pos,i-pos+1);
			long long curNum=stoll(curNumS);
			if(pos==0)
				dfs(i+1,curNumS,curNum,curNum);
			else
			{
				dfs(i+1,str+"*"+curNumS,sum-last+last*curNum,last*curNum);
				dfs(i+1,str+"+"+curNumS,sum+curNum,curNum);
				dfs(i+1,str+"-"+curNumS,sum-curNum,-curNum);
			}
			if(num[pos]=='0')
				break;
		}

	}
    vector<string> addOperators(string num, int target) {
        this->num=num;
        this->target=target;
        dfs(0,"",0,0);
        return ans;
    }
private:
	string num;
	int target;
	vector<string> ans;
};