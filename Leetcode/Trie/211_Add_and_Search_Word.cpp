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

    bool regular_find(const string & word) 
    {
    	return regular_find_sub(root.get(),0,word);
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

    bool regular_find_sub(TrieNode * t, int i, const string & word)
    {
    	if (i==word.size())
    		{
    			if (t->is_word)
    				return true;
    			else
    				return false;
    		}

    	for (int k=i;k<int(word.size());k++)
    	{

    		if (word[k]=='.')
    		{
    			std::vector< char > keys;
				keys.reserve(t->children.size());
				for(auto kv : t->children) {
					keys.push_back(kv.first);
				}
				bool ret=false;
				for(auto key:keys){
					ret=ret | regular_find_sub(t->children[key],k+1,word);
					if (ret ) return true;
				}
				return ret;
    		}
    		else if (t->children.count(word[k]))
    		{
    			t=t->children[word[k]];
    		}
    		else
    		{
    			return false;
    		}
    	}
    	return t->is_word;
    }

    std::unique_ptr <TrieNode> root;
};



class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

        t=new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        t->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
    	return t->regular_find(word); 
    }
private:
	Trie * t;
};

int main(){
	WordDictionary * obj = new WordDictionary();
	obj->addWord("bad");
	obj->addWord("dad");
	obj->addWord("mad");

	std::cout<<obj->search("pad");
	std::cout<<obj->search("bad") ;
	std::cout<<obj->search(".ad");
	std::cout<<obj->search("b..");

}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */