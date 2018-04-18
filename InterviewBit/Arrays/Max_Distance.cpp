//Need to find a better way to sort with index.
//https://stackoverflow.com/questions/3909272/sorting-two-corresponding-arrays
int Solution::maximumGap(const vector<int> &A) {
	
	vector<int> newA;
	for(int i=0;i<A.size();i++)
		{
			newA.push_back(i);
			
		}
	
	sort(newA.begin(),newA.end(),[&A](const int  & i, const int & j){return A[i]<A[j];});
	
	
	int ret=0;
	int maximum=INT_MIN;
	for(int i=A.size()-1;i>=1;i--)
	{
		maximum=max(newA[i],maximum);
		ret=max(maximum-newA[i-1],ret);
	}
	return ret;
}
