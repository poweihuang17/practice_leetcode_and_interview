class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int dp[7][7][7][7][7][7]={INT_MAX};
        int n=price.size();
        for(int i=n;i<6;i++)
        {
        	price.push_back(0);
        	needs.push_back(0);
        }
        for (int i = special.size() - 1; i >= 0; i--)
    	{	  
            int t = special[i][n];  
            special[i][n] = 0;  
            for (int j = n + 1; j < 7; j++)  
                special[i].push_back(0);  
            special[i][6] = t;  
    	}  
    	int m=special.size();
	   	for (int j = 0; j <=needs[0]; j++)    
	        for (int k = 0; k <=needs[1]; k++)  
	        for (int p = 0; p <=needs[2]; p++)  
	        for (int q = 0; q <=needs[3]; q++)  
	        for (int r = 0; r <=needs[4]; r++)  
	        for (int s = 0; s <=needs[5]; s++)  
	            dp[j][k][p][q][r][s]=j*price[0]+k*price[1]+p*price[2]+q*price[3]+r*price[4]+s*price[5];  
	    
        
	    for (int i = 0; i < m; i++)      
            for (int j = special[i][0]; j <=needs[0]; j++)  
            for (int k = special[i][1]; k <=needs[1]; k++)  
            for (int p = special[i][2]; p <=needs[2]; p++)  
            for (int q = special[i][3]; q <=needs[3]; q++)  
            for (int r = special[i][4]; r <=needs[4]; r++)  
            for (int s = special[i][5]; s <=needs[5]; s++)  
            {  
                int tt=dp[j-special[i][0]][k-special[i][1]][p-special[i][2]]  
                    [q-special[i][3]][r-special[i][4]][s-special[i][5]];  
                if (tt != INT_MAX)  
                    dp[j][k][p][q][r][s]=min(dp[j][k][p][q][r][s],tt+special[i][6]);  
            } 
        return dp[needs[0]][needs[1]][needs[2]][needs[3]][needs[4]][needs[5]]; 
    }
};