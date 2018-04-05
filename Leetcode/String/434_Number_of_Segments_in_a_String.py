class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        if(len(s)==0): 
            return 0
        s=re.split(" +", s)
        count=0
        for item in s:
            if item!="":
                count+=1
        return count