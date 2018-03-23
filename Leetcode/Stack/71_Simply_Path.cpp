class Solution {
public:
    string simplifyPath(string path) {
        stack<string> mystack;
        string delimiter="/";
        int pos;
        while( (pos=path.find(delimiter))!=string::npos)
        {
        	string token=path.substr(0,pos);
        	path.erase(0,pos+delimiter.length());
        	if(token=="")
        		continue;
        	else if(token==".")
        		continue;
        	else if (token==".." && mystack.size()>0)
        		mystack.pop();
        	else if(token!="..")
        		mystack.push(token);
    	}


        if (path==".." && mystack.size()>0)
        	mystack.pop();
        else if(path!="" && path!="." && path!="..")
        	mystack.push(path);

        string res;
    	if(mystack.empty()) res="/";
    	while(!mystack.empty())
    	{
            if(mystack.top()!="")
            {
                
                res="/"+mystack.top()+res;
    		    
            }
    		mystack.pop();
    	}
    	return res;
    }
};