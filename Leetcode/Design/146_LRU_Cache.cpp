//Why do we need to put par inside the list?
#include <list>

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity_=capacity;
    }
    
    int get(int key) {
        const auto it=m_.find(key);

        if(it == m_.cend()) return -1;

        //Still not sure
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        const auto it=m_.find(key);

        if(it != m_.cend())
        {
        	it->second->second=value;
        	cache_.splice(cache_.begin(),cache_,it->second);
        	return ;
        }

        if(cache_.size()==capacity_)
        {
        	const auto & node=cache_.back();
        	m_.erase(node.first);
        	cache_.pop_back();
        }
        cache_.emplace_front(key,value);
        m_[key]=cache_.begin();
    }

private:
	int capacity_;
	list<pair<int,int>> cache_;
	unordered_map<int, list<pair<int,int>>::iterator> m_;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */