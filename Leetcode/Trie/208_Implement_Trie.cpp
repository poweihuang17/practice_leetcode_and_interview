#include <unordered_map>
#include <string>
#include <iostream>
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




// Your Trie object will be instantiated and called as such:
int main(){
    Trie *obj = new Trie();
    obj->insert("abc");
    bool param_2 = obj->search("abc");
    bool param_3 = obj->search("ab");
    obj->insert("ab");
    bool param_5 = obj->search("ab");
    obj->insert("ab");
    bool param_7 = obj->search("ab");
}


 