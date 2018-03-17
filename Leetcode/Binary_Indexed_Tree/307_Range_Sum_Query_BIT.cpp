#include <vector>
using namespace std;

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
    static inline int lowbit(int x) { 
        return x & (-x); 
    }
    vector<int> sums_;
};




class NumArray {
public:
    NumArray(vector<int> nums):t(nums.size()) ,nums_(std::move(nums)){
        for(int i=0;i<nums_.size();i++)
        {
            t.update(i+1,nums_[i]);
        }
    }
    
    void update(int i, int val) {
        int now=nums_[i];
        t.update(i+1,val-now);
        nums_[i]=val;
        
    }
    
    int sumRange(int i, int j) {
        return t.query(j+1)-t.query(i);
    }

private:
    FenwickTree t;
    vector<int> nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */