class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """

        #Count the frequency
        count=collections.defaultdict(int)
        max_count=0
        for task in tasks:
        	count[task]+=1
        	max_count=max(max_count, count[task])

        #Counting the interval
        result=(max_count-1)*(n+1)
        for num in count.values():
        	if num==max_count:
        		result+=1

        return max(result, len(tasks))

