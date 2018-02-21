class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        
        maxlen=0
        length_table={0:0}

        for line in input.splitlines():

        	name=line.lstrip('\t')
        	depth=len(line)-len(name)

        	if '.' in name:
        		maxlen=max(maxlen, length_table[depth]+len(name))
        	else:
        		length_table[depth+1]=length_table[depth]+1+len(name)

        return maxlen

print Solution().lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext")

