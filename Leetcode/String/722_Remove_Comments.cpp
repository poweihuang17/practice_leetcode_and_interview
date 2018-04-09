class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
    	
    	bool in_block=false;
    	vector<string> ans;
    	string sf;

        for(int i=0;i<source.size();i++)
        {
        	for(int j=0;j<source[i].size();)
        	{
	        	if(in_block==false)
	        	{
	        		if(j+1==source[i].size()) sf+=source[i][j++]; 
	        		else
	        		{
	        			string m=source[i].substr(j,2);
	        			if(m=="/*") {
	        				in_block=true;
	        				j+=2;
	        			}
	        			else if(m=="//")
	        				break;
	        			else 
	        				sf+=source[i][j++];
	        		}
	        	}
	        	else
	        	{
	        		if(j+1==source[i].size()) j++;
	        		else{
	        			string m=source[i].substr(j,2);
	        			if(m=="*/"){
	        			in_block=false;
	        			j+=2;
	        			}
	        			else
	        				j++;
	        		}
	        	}
        	}

        if(sf.size() && !in_block) // && !in_block
        	{
        		ans.push_back(sf);
        		sf="";
        	}
        }
        return ans;

    }
};