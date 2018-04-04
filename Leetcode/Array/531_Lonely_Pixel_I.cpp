class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if(picture.size()==0 || picture[0].size()==0) return 0;
        for(int i=0;i<picture.size();i++)
        	picture[i].push_back('W');
        picture.push_back(vector<char>(picture[0].size(),'W'));

        for(int i=0;i<picture.size()-1;i++)
        {
        	for(int j=0;j<picture[0].size()-1;j++)
        	{
        		if(picture[i][j]=='B') 
        		{
                    picture[i][picture[0].size()-1]=picture[i][picture[0].size()-1]=='W'?'B':'Z';
        			picture[picture.size()-1][j]=picture[picture.size()-1][j]=='W'?'B':'Z';    
        		}
        	}
        }
        int count=0;
        for(int i=0;i<picture.size()-1;i++)
        	for(int j=0;j<picture[0].size()-1;j++)
        		if(picture[i][j]=='B' && picture[i][picture[0].size()-1]=='B' && picture[picture.size()-1][j]=='B')
        			count++;
        return count;
    }
};