# Question : How to avoid copy across function callls in python?
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """

        digits_map={"2":"abc", "3":"def","4":"ghi","5":"jkl","6":"mno",
        "7":"pqrs","8":"tuv","9":"wxyz","0":""}

        if digits=="":
        	return []
        elif len(digits)==1:
        	return list(digits_map[digits])

        return [s+c for s in self.letterCombinations(digits[:-1]) for c in digits_map[digits[-1]]]

print Solution().letterCombinations("23")
        	