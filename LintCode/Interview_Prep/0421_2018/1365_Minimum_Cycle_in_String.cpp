class Solution {
public:
    /**
     * @param array: an integer array
     * @return: the length of the minimum cycle section
     */
    int minimumCycleSection(vector<int> &array) {
        // Write your code here
        for(int i=1;i<array.size();i++)
        {
            vector<int> start;
            for(int j=0;j<array.size();j+=i)
                start.push_back(j);
            bool u=true;
            for(int k=0;k<i;k++)
                {
                    bool x=true;
                    for(int l=1;l<start.size();l++)
                        if(start[l]+k<array.size() && array[start[0]+k]!=array[start[l]+k])
                            {x=false;break;}
                    if(x==false)
                        {u=false;break;}
                }
            if(u) return i;
        }
        return array.size();
    }
};