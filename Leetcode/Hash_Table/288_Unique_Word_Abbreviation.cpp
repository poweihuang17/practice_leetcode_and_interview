class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary):dictionary_(dictionary){
    	for(auto & word:dictionary)
    	{
            if(word.size()<=2 && table[word]>=1)
                continue;
    		table[transform(word)]+=1;
    	}
    }
    
    bool isUnique(string word) {
        int x=table[transform(word)];
    	if(x>=2 ||(x==1 && find(dictionary_.begin(), dictionary_.end(), word)==dictionary_.end()) )
    		return false;
    	else
        	return true;
    }

private:
	unordered_map<string,int> table;

	string transform(const string & word)
	{
		if(word.size()<=2) return word;
		string temp(3,' ');
    	temp[0]=word[0];
    	temp[2]=word[word.size()-1];
    	temp[1]='0'+word.size()-2;
    	return temp;
	}
    vector<string> dictionary_;

};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */