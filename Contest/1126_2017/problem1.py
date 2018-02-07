class Solution(object):
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        task=[]
        #result=[]
        height=len(image)
        width=len(image[0])
        task.append((sr,sc))
        #result.append((sr,sc))

        old_Color=image[sr][sc]
        if newColor==old_Color:
            return image
        image[sr][sc]=newColor


        
        while task:
            task_now=task.pop()
            sr_now=task_now[0]
            sc_now=task_now[1]
            image[sr_now][sc_now]=newColor
            if (sr_now-1)>=0 and image[sr_now-1][sc_now]==old_Color:
                
                task.append((sr_now-1,sc_now))
                image[sr_now-1][sc_now]=newColor
                
           
            if  (sc_now-1)>=0 and image[sr_now][sc_now-1]==old_Color:
                
                image[sr_now][sc_now-1]=newColor
                task.append((sr_now,sc_now-1))
                
            if (sc_now+1)<width and image[sr_now][sc_now+1]==old_Color:
                
                image[sr_now][sc_now+1]=newColor
                task.append((sr_now,sc_now+1))
                
            if (sr_now+1)<height and image[sr_now+1][sc_now]==old_Color:
                
                image[sr_now+1][sc_now]=newColor
                task.append((sr_now+1,sc_now))
            
            print task
            print image

       # for s in result:
        #    image[s[0]][s[1]]=newColor
        #image[sr][sc]=newColor
        return image
                
        
if __name__ == '__main__':
    Solution=Solution()
    Solution.floodFill([[0,0,0],[0,1,1]],1,1,1)