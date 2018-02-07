class Solution(object):
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        result=[]
        
        collide_flag=0
        
        while 1:
            #print asteroids
            #print result

            pass1=[0 for x in range(len(asteroids))]
            
            for idx, x in enumerate(asteroids):
                if pass1[idx] :
                    continue
                if idx==(len(asteroids)-1):
                    result.append(x)
                    continue

                if (asteroids[idx+1]/abs(asteroids[idx+1])) < (x/abs(x)):
                    # collide
                    collide_flag=1
                    if abs(x)==abs(asteroids[idx+1]):
                        pass1[idx+1]=True
                        continue

                    elif abs(x)>abs(asteroids[idx+1]):
                        pass1[idx+1]=True
                        result.append(x)
                    elif abs(x)<abs(asteroids[idx+1]):
                        pass1[idx+1]=True
                        result.append(asteroids[idx+1])

                else:
                    result.append(x)
            
            if collide_flag==0:
                break

            asteroids=result
            result=[]
            collide_flag=0


        
        return result
if __name__ == '__main__':
    Solution=Solution()
    print Solution.asteroidCollision([5, 10, -5])