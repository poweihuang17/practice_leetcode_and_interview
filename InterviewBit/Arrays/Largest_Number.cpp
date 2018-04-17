#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string Solution::largestNumber(const vector<int> &A) {
	vector<int> B=A;
    auto compare=[](const int & a, const int & b)
    {
        if(b==0) return true;
        else if(a==0) return false;
        
        vector<int> da,db;
        int t1=a,t2=b;
        while(t1!=0)
        {
        	da.push_back(t1%10);
        	t1=t1/10;
        }
        while(t2!=0)
        {
        	db.push_back(t2%10);
        	t2=t2/10;
        }
        int i=da.size()-1, j=db.size()-1;
        while(i>=0 && j>=0)
        {
        	if(da[i]>db[j])
        		return true;
        	else if (da[i]<db[j])
        		return false;
        	else
        	{
        		i--;
        		j--;
        	}
        }
        if(i>=0)
            return da[i]>db[0];
        else if(j>=0) return da[0]>db[j];
        else
        	return true;
    };

    sort(B.begin(),B.end(),compare);
    string res;
    for(int i=0;i<=B.size()-1;i++)
    {
    	res+=to_string(B[i]);
    }
    string ret;
    bool found=false;
    for(auto & c:res)
        {
            if(c=='0' && !found) continue;
            else
                {
                    ret+=c;
                    found=true;
                }
        }
    if(ret.size()==0) return "0";
    return ret;
}



int main(){
	vector<int> A{3, 30, 34, 5, 9};
	largestNumber(A);
}


string Solution::largestNumber(const vector<int> &A) {
	vector<int> B=A;
    auto compare=[](const int & a, const int & b)
    {
        if(a==0 && b==0) return true;
        else if(a==0) return false;
        else if(b==0) return true;
        
        string sa=to_string(a);
        string sb=to_string(b);
        return  stol(sa+sb)>stol(sb+sa);
    };

    sort(B.begin(),B.end(),compare);
    string res;
    for(int i=0;i<=B.size()-1;i++)
    {
    	res+=to_string(B[i]);
    }
    string ret;
    bool found=false;
    for(auto & c:res)
        {
            if(c=='0' && !found) continue;
            else
                {
                    ret+=c;
                    found=true;
                }
        }
    if(ret.size()==0) return "0";
    return ret;
}
