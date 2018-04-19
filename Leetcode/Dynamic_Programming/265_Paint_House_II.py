class Solution(object):
    def minCostII(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        if not costs or not costs[0]:
            return 0

        n=len(costs)
        k=len(costs[0])

        min1=-1
        min2=-1

        for i in range(len(costs)):
            last1=min1
            last2=min2
            min1=-1
            min2=-1

            for j in range(len(costs[0])):
                if j!=last1:
                    costs[i][j]+=(0 if last1<0 else costs[i-1][last1])
                else:
                    costs[i][j]+=(0 if last2<0 else costs[i-1][last2])

                if (min1<0 or costs[i][j]<costs[i][min1]):
                    min2=min1
                    min1=j
                elif (min2<0 or costs[i][j]<costs[i][min2]):
                    min2=j
        #print costs
        return costs[n-1][min1]

s=Solution()
costs=[[1,5,3],[2,9,4]]
s.minCostII(costs)
