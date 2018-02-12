import collections

class Solution(object):
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """

        counter=collections.Counter(S)
        catch=set()
        
        count_id=0
        result=[]

        for i,s in enumerate(S):
        	
        	catch.add(s)
        	counter[s]-=1
        	count_id+=1

        	if counter[s]==0:
        		catch.remove(s)
        		if len(catch)==0:
        			result.append(count_id)
        			count_id=0

        return result

s=Solution()
print s.partitionLabels("ababcbacadefegdehijhklij")


