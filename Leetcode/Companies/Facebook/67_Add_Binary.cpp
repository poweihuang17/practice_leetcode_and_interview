class Solution {
public:
    string addBinary(string a, string b) {
        
        int i=a.size()-1,j=b.size()-1,c=0;
        string res="";

        while(i>=0 || j>=0 || c>0)
        {
        	int temp=0;
int d=i>=0 && a[i]=='1'?1:0;
int e=j>=0 && b[j]=='1'?1:0;
            int nextc=(c+d+e)>=2 ? 1:0;
        	temp=(c ^ d ^e)?1:0;
        	string y=temp==1?"1":"0";
res=y+res;
i--;
j--;
c=nextc;
}
        return res;
    }
};