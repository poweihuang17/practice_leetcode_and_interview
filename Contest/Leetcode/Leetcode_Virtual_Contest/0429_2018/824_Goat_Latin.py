class Solution(object):
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        s=S.split(' ')
        index=1
        s2=[]
        for word in s:
        	if word[0] in ['a','e','i','o','u','I','A','E','O','U']:
        		word+="ma"
        	else:
        		word=word[1:]+word[0]+"ma"
        	for i in range(index):
        		word+="a"
        	index+=1
        	s2.append(word)
        return ' '.join(s2)