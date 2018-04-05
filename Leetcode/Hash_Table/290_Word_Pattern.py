class Solution(object):
	def wordPattern(self, pattern, str):
		"""
		:type pattern: str
		:type str: str
		:rtype: bool
		"""
		dict={}
		reverse_dict=set()
		str=str.split(' ')
		if len(str)!=len(pattern):
			return False
		for i in xrange(len(pattern)):
			if pattern[i] in dict:
				if dict[pattern[i]]!=str[i]:
					return False
			else:
				if str[i] not in reverse_dict:
					reverse_dict.add(str[i])
				else:
					return False
				dict[pattern[i]]=str[i]

		return True