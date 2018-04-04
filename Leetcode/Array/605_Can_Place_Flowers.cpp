class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    	if (flowerbed.size()==0) return 0;

        int count=0;
        for(int i=0;i<flowerbed.size();i++)
        {
        	if(flowerbed[i]==1)
        		continue;
        	bool plant=true;
        	if(i>=1 && flowerbed[i-1]==1)
        		plant=false;
        	if(i<flowerbed.size()-1 && flowerbed[i+1]==1)
        		plant=false;

        	if(plant)
        		{
        			flowerbed[i]=1;
        			count++;
        		}
        }
        //cout<<count;
        if(n>count )return false;
        else return true;
    }
};