class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int n=ages.size();
        int ret=0;
        for(int i=n-1;i>=0;i--)
        {
            int x1=0.5 * ages[i] + 7;
            bool x2=ages[i]<100;
            for(int j=i-1;j>=0;j--)
            {
                if( ages[j] <= x1)
                    break;
                if(x2 && ages[j] > 100)
                    break;
                
                if(ages[i]==ages[j])
                    ret+=2;
                else
                {//cout<<ages[i]<<" "<<ages[j]<<endl;
                    ret+=1;}
            }
        }
        return ret;
    }
};