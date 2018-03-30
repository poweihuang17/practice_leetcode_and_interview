class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(h.count(val)) return false;
        h[val]=v.size();
        v.push_back(val);
        return true;

    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!h.count(val)) return false;
        h[v.back()]=h[val];
        swap(v[h[val]], v.back());
        v.pop_back();
        h.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index=rand()%v.size();
        return v[index];
    }

private:
    vector<int> v;
    unordered_map<int, int> h;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */