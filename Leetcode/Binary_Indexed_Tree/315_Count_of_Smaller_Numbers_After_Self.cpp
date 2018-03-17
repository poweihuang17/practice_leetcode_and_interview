class FenwickTree {    
public:
    FenwickTree(int n): sums_(n + 1, 0) {}
    
    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) const {        
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
private:
    static inline int lowbit(int x) { return x & (-x); }
    vector<int> sums_;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
     
     set<int> sorted(nums.begin(),nums.end());
     unordered_map<int,int> ranks;

     int rank=0;  
     for(const int num : sorted)
     	ranks[num]=++rank; 

     vector<int> ans;
     FenwickTree tree(nums.size());
     for(int i=nums.size()-1;i>=0;--i)
     {
     	ans.push_back(tree.query(ranks[nums[i]]-1));
     	tree.update(ranks[nums[i]],1);
     }

     std::reverse(ans.begin(),ans.end());
     return ans;
    }
};