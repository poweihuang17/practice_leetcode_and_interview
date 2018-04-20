class Solution {
public:
    string toHex(int num) {
    	if(num==0) return "0";

        unsigned int x=num;
        string s;
        while(x!=0)
        {
        	int y=x%16;
        	x>>=4;
            cout<<y<<endl;
        	if(y>=0 && y<=9)
                {
                string temp(1,'0'+y);
                s=temp+s;
                }
        	else if(y>=10 && y<=15)
                {
                string temp(1,'a'+(y-10));
                s=temp+s;
                }
        }
        return s;
    }
};