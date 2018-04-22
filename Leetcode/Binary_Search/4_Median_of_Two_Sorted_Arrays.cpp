class Solution {

private:
    int count(vector<int>& nums1, vector<int>& nums2, int number,int & result1,int & result2)
    {
        int ret=0;
        result1=INT_MAX;
        result2=INT_MIN;
        if(nums1.size())
        {
            auto it=upper_bound(nums1.begin(),nums1.end(),number);
            ret+=( it-nums1.begin());
            result1=it==nums1.end()?result1:min(result1,*it);
            result2=it==nums1.begin()?result2:max(result2,*(it-1));
        }

        if(nums2.size())
        {
            auto it=upper_bound(nums2.begin(),nums2.end(),number);
            ret+=( it-nums2.begin());
            result1=it==nums2.end()?result1:min(result1,*it);
            result2=it==nums2.begin()?result2:max(result2,*(it-1));
        }


        return ret;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int target=(m+n)/2;
        int i=1,j=INT_MAX;

        while(i<j)
        {
            int mid=i+(j-i)/2;
            int result1;
            int result2;
            int k=count(nums1,nums2,mid,result1,result2);
            if(k==target)
                {
                    //cout<<result1<<endl;
                    //cout<<result2<<endl;
                    //cout<<mid;
                    if((m+n)%2)
                        return result1==INT_MAX? result2:result1;
                    else
                        return ((double)result1+(double)result2)/2.0;
                }
            
            else if(k>target)
                j=mid;
            else
                i=mid+1;
            
        }
        

        return i;
    }

};