class Solution(object):
    def monotoneIncreasingDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        
        number=[int(x) for  x in str(N)]

        def test(mylist):
        	index=-1
        	for i in range(0,len(mylist)-1):
        		if mylist[i+1]<mylist[i]:
        			index=i
        			break

        	return index 

        pointer=0
        index=test(number)
        while index!=-1:
        	number[index]-=1
        	for i in range(index+1,len(number)):
        		number[i]=9
        	index=test(number)

        for i in range(len(number)):
        	number[i]=str(number[i])
        
        return int(''.join(number).lstrip('0'))

s=Solution()
print s.monotoneIncreasingDigits(1234)
print s.monotoneIncreasingDigits(10)
print s.monotoneIncreasingDigits(332)
print s.monotoneIncreasingDigits(100)