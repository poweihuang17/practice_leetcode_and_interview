class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        vector<int> res(houses.size(), INT_MAX);

        for(int i=0,h=0; i< houses.size() && h<heaters.size();)
        {
        	if(houses[i]<=heaters[h]) {
        		res[i]=heaters[h]-houses[i];
        		i++;
        	}
        	else
        		h++;
        }
        for(int i=houses.size()-1, h=heaters.size()-1; i>=0 && h>=0;)
        {
        	if(houses[i]>=heaters[h]){
        		res[i]=min(res[i],houses[i]-heaters[h]);
        		i--;
        	}
        	else
        		h--;
        	
        }
        return *max_element(res.begin(),res.end());
    }
};