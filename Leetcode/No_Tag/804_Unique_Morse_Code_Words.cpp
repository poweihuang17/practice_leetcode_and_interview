class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mapping{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string,bool> table;
        for(auto & word:words)
        {
        	string d;
        	for(auto& c:word)
        	{
        		d+=mapping[c-'a'];
        	}
        	table[d]=true;
        }
        return table.size();
    }
};