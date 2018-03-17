class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> count;
        vector<int> ans;
        for(auto & num: nums1)
        {
        	if(count.count(num))
        		count[num]++;
        	else
        		count[num]=1;
        }
        for(auto & num: nums2)
        {
        	if(count.count(num) && count[num]>0)
        	{
        		ans.push_back(num);
        		count[num]--;
        	}
        
        }
        return ans;
    }
};

/*
Follow up:

    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/