class Solution {
public:
    vector<int> constructRectangle(int area) {
        int a=area,b=1;
        int end=1;
        for(int i=area-1;i>end;i--)
        {
        	if(area%i==0) {
        		a=i;
        		end=area/i;
        		b=end;
        	}
        }

        return vector<int>{a,b}; 
    }
};