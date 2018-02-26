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

    std::unique_ptr <TrieNode> root;
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie * t=new Trie();
        for (auto word: words)
        {
        	t->insert(word);
        }

        unsigned long best=0;
        string ret;

        for (auto word:words)
        {
        	if (word.length()<best)
        		continue;
        	
        	if(t->hasAllPrefixes(word))
        		{
        		//std::cout<<word<<'\n';
        		if (word.length()==best)
        			{
        				if(ret>=word) 
        				{	
        					
        					ret=word;
        				}
        			}
        		else
        			{
        			
        			ret=word;
        			}
        			

        		best=max(word.length(),best);
        		}
        }
        return ret;
    }
};

int main(){
    Solution * obj= new Solution();
    vector<string> a={"w","wo","wor","worl", "world"};
    std::cout<<Solution().longestWord(a );
    vector<string> b={"a", "banana", "app", "appl", "ap", "apply", "apple"};
    std::cout<<Solution().longestWord(b);

    vector<string> c={"t","ti","tig","tige","tiger","e","en","eng","engl","engli","englis","english","h","hi","his","hist","histo","histor","history"};
    std::cout<<Solution().longestWord(c);
}

