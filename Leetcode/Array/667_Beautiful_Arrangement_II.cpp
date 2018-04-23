class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> mVec;

        // 最大n-1
        for(int i = 1,j = n;i<=j;) {
            if(k>1) {
                mVec.push_back(k--%2?i++:j--);
            }else {
                mVec.push_back(i++);
            }
        }
        return mVec;

    }

};