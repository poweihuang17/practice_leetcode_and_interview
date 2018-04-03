class WordDistance {
public:
    WordDistance(vector<string> words) {
        table.clear();
        for(int i=0;i<words.size();i++)
        {
        	table[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> & w1=table[word1];
        vector<int> & w2=table[word2];
        int i=0,j=0,diff=INT_MAX;
        while(i<w1.size() && j<w2.size())
        {
        	if(w1[i]>w2[j])
        	{
        		diff=min(diff,w1[i]-w2[j]);
        		j++;
        	}
        	else
        	{
        		diff=min(diff,w2[j]-w1[i]);
        		i++;
        	}
        }
        return diff;
    }

private:

	unordered_map<string,vector<int> > table;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */