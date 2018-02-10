class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        
        tank=0
        total_tank=0
        start_index=0
        
        for i,g in enumerate(gas):
            diff=g-cost[i]
            tank+=diff
            total_tank+=diff
            
            if tank<0:
                start_index=i+1
                tank=0
        
        if total_tank<0:
            return -1
        return start_index
        