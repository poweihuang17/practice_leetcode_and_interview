#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): root(new TrieNode()) {}
        
    
    
    /** Inserts a word into the trie. */
    void insert(const string & word, int & insert_number) {
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
        p->number=insert_number;

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

    int find_sum(const string  prefix) {
    	TrieNode * p= root.get();
    	for (auto c: prefix)
    	{
    		if (p->children.count(c))
    			p=p->children[c];
    		else 
    			return 0;
    	}

    	return find_sum_collect( p);
    }



private:



    struct TrieNode {
        TrieNode():is_word(false),number(0){}
        ~TrieNode(){
            for (auto&kv:children)
                if (kv.second)
                    delete kv.second;
        }

        bool is_word;
        int number;
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

    int find_sum_collect(TrieNode * p)
	{
		int temp=0;
		if(p->is_word)
			temp=p->number;

		for(auto & kv:p->children)
		{
			if(kv.second)
				temp+=find_sum_collect(kv.second);
		}
		return temp;
	}

    std::unique_ptr <TrieNode> root;
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
    	Trie t=Trie();
    }
    
    void insert(string key, int val) {
        t.insert(key, val);
    }
    
    int sum(string prefix) {
        return t.find_sum(prefix);
    }

private:
	Trie t;
};

int main()
{
	MapSum m=MapSum();
	m.insert("apple",3);
	std::cout<<m.sum("ap")<<endl;
	m.insert("app",2);
	std::cout<<m.sum("ap")<<endl;

	MapSum m2=MapSum();
	m2.insert("a",3);
	std::cout<<m2.sum("ap")<<endl;
	m2.insert("b",2);
	std::cout<<m2.sum("a")<<endl;
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */