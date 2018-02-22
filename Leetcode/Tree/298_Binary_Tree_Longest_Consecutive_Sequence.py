# Definition for a binary tree node.
class TreeNode(object):
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution(object):
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
        	return 0
        treestack=[(1,root)]
        valuestack=[]
        length=1
        

        while treestack:
        	#print treestack
        	#print valuestack
        	(depth,mynode)=treestack.pop()
        	myvalue=mynode.val
        	if valuestack:
        		
        		while len(valuestack)+1 > depth:
        			valuestack.pop()

        		#print (myvalue,valuestack[-1][0]+1)
        		if myvalue==(valuestack[-1][0]+1):
					temp_counter=valuestack[-1][1]+1
					#print temp_counter
					length=max(temp_counter,length)
        		else:
        			temp_counter=1
        		
        		if mynode.left or mynode.right:
        			valuestack.append((myvalue,temp_counter))
        		
        			

        	elif len(valuestack)==0:
        		valuestack.append((myvalue,1))	
        		


        	if mynode.right:
        		treestack.append((depth+1,mynode.right))
        	if mynode.left:
        		treestack.append((depth+1,mynode.left))

        return length

class Solution2(object):
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
        	return 0
        maximum=0
        stack=[(root,1)]
        while stack:

        	node,cnt=stack.pop()
        	#print cnt
        	if node.left:
        		stack.append((node.left, cnt+1 if node.left.val==node.val+1 else 1))
        	if node.right:
        		stack.append((node.right,cnt+1 if node.right.val==node.val+1 else 1))
        	#print cnt
        	maximum=max(cnt,maximum)
        return maximum



tree1=TreeNode(1)
#tree1.left=TreeNode(3)
#tree1.left.left=TreeNode(2)
#tree1.left.right=TreeNode(3)
tree1.right=TreeNode(3)
tree1.right.left=TreeNode(2)
tree1.right.right=TreeNode(4)
tree1.right.right.right=TreeNode(5)

print Solution2().longestConsecutive(tree1)



