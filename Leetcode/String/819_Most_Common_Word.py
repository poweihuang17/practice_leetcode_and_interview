class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        count={}
        paragraph=paragraph.split(' ')

        m=float('-inf')
        exclude = set(string.punctuation)
        for word in paragraph:
            
            word = ''.join(ch for ch in word if ch not in exclude)
            word=word.lower()
            #print word
            if word not in banned:
        		count[word]=count.get(word,0)+1;
        		if m<count[word]:
        			m=count[word]
        			most_common=word
        return most_common
        		


