class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
    	vector<int> posR, posC;
        for(int i=0;i<grid.size();i++)
        	for(int j=0;j<grid[0].size();j++)
        		if(grid[i][j]==1)
        		{
        			posR.push_back(i);
        			posC.push_back(j);
        		}
    	int med1 = posR[posR.size() / 2];
    	nth_element(posC.begin(), posC.begin() +  posC.size() / 2, posC.end());
    	int med2 = posC[posC.size() / 2];
        int total=0;
    	for (auto pos1 : posR) total += abs(pos1 - med1);
    	for (auto pos2 : posC) total += abs(pos2 - med2);
    	return total;
    }
};