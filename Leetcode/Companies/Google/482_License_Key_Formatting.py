class Solution(object):
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        mylist=S.split('-')
        mystring=''.join(mylist)
        r=len(mystring)%K
        mylist=[]
        if r!=0:
        	mylist.append(mystring[:r])
        m=(len(mystring)-r)/K
        
        for i in range(m):
        	mylist.append(mystring[r+i*K: r+(i+1)*K])

        return '-'.join(mylist).upper()

print Solution().licenseKeyFormatting( "5F3Z-2e-9-w",4)
print Solution().licenseKeyFormatting("2-5g-3-J",2)
