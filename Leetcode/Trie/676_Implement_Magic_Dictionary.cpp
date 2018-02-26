#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): root(new TrieNode()) {}
        
    
    
    /** Inserts a word into the trie. */
    void insert(const string & word) {
        TrieNode * p=root.get();
        for (const char c: word){
            //std::cout << p->children.count(c);
            if (p->children.count(c))
                p=p->children[c];
            else
                {
                p->children[c]=new TrieNode();
                p=p->children[c];
                }
        }
        p->is_word=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string & word) const {

        const TrieNode * p = this->find(word);
        return p && p->is_word;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string & prefix) const {
         
        return find(prefix) != nullptr;
    }

    bool hasAllPrefixes(const string & word) const{
		TrieNode* p = root.get();
    	for (const char c: word)
    	{
    		if (!p->children.count(c))
    			return false;
    		p=p->children[c];
    		if(!p->is_word) return false;
    	}
    	return true;
    }

    bool relaxedsearch(const string & word)
    	{
    		TrieNode * p =root.get();
    		return relaxedsearchNode(p,word,0,0);
    	}

    

private:

    struct TrieNode {
        TrieNode():is_word(false){}
        ~TrieNode(){
            for (auto&kv:children)
                if (kv.second)
                    delete kv.second;
        }

        bool is_word;
        unordered_map<char, TrieNode * > children;
    };

    const TrieNode * find(const string & prefix) const{
        const TrieNode * p= root.get();
        for (const char c:prefix){
            if (!p->children.count(c)) return nullptr;
            p=p->children.at(c);   
        }
        return p;
    }

    bool relaxedsearchNode(TrieNode * p, const string & word ,int start_index, int change) const{
    	
    	if  (change>1)
    		return false;
    	if (start_index==int(word.length()) and change==1 and p->is_word)
    		return true;

    	for (int i=start_index;i<int(word.length());i++)
    	{
    		/*
    		std::cout<<i<<'\n';
    		std::cout<<start_index<<'\n';
    		std::cout<<word<<'\n';
    		std::cout<<change<<'\n';
    		*/
    		std::vector< char > keys;
			keys.reserve(p->children.size());
			for(auto kv : p->children) {
				keys.push_back(kv.first);
				} 

    		if (!p->children.count(word[i]))
    			{
				bool result=false;
				for(auto key:keys)
					result = result| relaxedsearchNode(p->children[key],word,start_index+1, change+1);	
				return result;
    				
    			}
    		else
    		{
    			bool result2=false;
				for(auto key:keys)
				{
					if (key!=word[i])
						result2 = result2| relaxedsearchNode(p->children[key],word,start_index+1, change+1);
				}
    			
    			start_index++;
    			//std::cout<<i<<'\n'<<'\n';
    			p=p->children[word[i]];
    			
    			if(p->is_word && i==word.length()-1 && change==1) return true;

    			if(result2) return true;
    		}
    		
    	}
    	return false;
    }

    std::unique_ptr <TrieNode> root;
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
    	t= new Trie();
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto word: dict)
        {
        	t->insert(word);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
    	return t->relaxedsearch(word);
    }

private:
	Trie * t;
};

int main(){
    MagicDictionary * obj= new MagicDictionary();
    //vector<string> a={"hello", "hallo","leetcode"};
    vector<string> a={"a","b","ab","abc","abcabacbababdbadbfaejfoiawfjaojfaojefaowjfoawjfoawj","abcdefghijawefe","aefawoifjowajfowafjeoawjfaow","cba","cas","aaewfawi","babcda","bcd","awefj"};
    obj->buildDict(a);
    /*
   	std::cout<<obj->search("hello");
   	std::cout<<obj->search("hhllo");
   	std::cout<<obj->search("hell");
   	std::cout<<obj->search("leetcoded");
   	std::cout<<obj->search("helro");

   	std::cout<<obj->search("hello");
   	std::cout<<obj->search("hallo");
   	std::cout<<obj->search("hell");
   	
   	std::cout<<obj->search("leetcodd");
   	*/
   	std::cout<<obj->search("ab");
   	std::cout<<obj->search("ba");


};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */