class Solution {
public:
    /**
     * @param r: a Integer represent radius
     * @return: the circle's circumference nums[0] and area nums[1]
     */
    vector<double> calculate(int r) {
        // write your code here
        vector<double> ret(2);
        double PI=3.14;
        ret[0]=2*PI*r;
        ret[1]=PI*r*r;
        return ret;
    }
};