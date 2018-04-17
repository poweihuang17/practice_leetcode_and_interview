void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	for(int i=0;i<A.size();i++)
		A[i].push_back(0);
	A.push_back(vector<int>(A[0].size(),0));

	for(int i=0;i<A.size()-1;i++)
	{
		for(int j=0;j<A[i].size()-1;j++)
		{
			if(A[i][j]==0) 
			{
				A[i][A[0].size()-1]=1;
				A[A.size()-1][j]=1;
			}
		}
	}

	for(int i=0;i<A.size()-1;i++)
	{
		for(int j=0;j<A[i].size()-1;j++)
		{
			if(A[i][A[0].size()-1] || A[A.size()-1][j])
				A[i][j]=0;
		}
	}
	A.pop_back();
	for(int i=0;i<A.size();i++)
		A.pop_back();
	return A;
}

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    bool row1=false,column1=false;
    for(int i=0;i<A.size();i++)
        if(A[i][0]==0)
            {column1=true; break;}
            
    for(int i=0;i<A[0].size();i++)
        if(A[0][i]==0)
            {row1=true;break;}
    
	for(int i=1;i<A.size();i++)
	{
		for(int j=1;j<A[i].size();j++)
		{
			if(A[i][j]==0) 
			{
				A[i][0]=2;
				A[0][j]=2;
			}
		}
	}

	for(int i=1;i<A.size();i++)
	{
		for(int j=1;j<A[i].size();j++)
		{
			if(A[i][0]==2 || A[i][0]==0 || A[0][j]==0 || A[0][j]==2)
				A[i][j]=0;
		}
	}
	for(int i=0;i<A.size();i++)
	    A[i][0]=(A[i][0]==2 || column1)?0:A[i][0];
	for(int i=0;i<A[0].size();i++)
	    A[0][i]=(A[0][i]==2 || row1)? 0:A[0][i];
	    
}

