import operator

class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """

        candies=[1 for _ in xrange(len(ratings))]
        for i in xrange(len(ratings)-1):
       		if ratings[i+1]>ratings[i]:
       			candies[i+1]=candies[i]+1

       	for i in reversed(xrange(1,len(ratings))):
       		if ratings[i-1]>ratings[i] and candies[i-1]<=candies[i]:
       			candies[i-1]=candies[i]+1

       	return reduce(operator.add, candies)