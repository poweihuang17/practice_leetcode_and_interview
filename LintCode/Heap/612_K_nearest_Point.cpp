//How to 
#include <vector>
#include <queue>
using namespace std;
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * }; * Definition for a point.
 *
 */
  struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };


class Solution {
public:
    /**
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        // write your code here
        for(auto & point:points)
        {
            point.x-=origin.x;
            point.y-=origin.y;
        }
        
        auto compare=[](Point & a,Point & b)
        {
            int x=a.x;
            int y=a.y;
            int x2=b.x;
            int y2=b.y;

            if( (x*x+y*y)<(x2*x2+y2*y2) )
                return true;
            else if ((x*x+y*y)==(x2*x2+y2*y2) && x<x2)
                return true;
            else if((x*x+y*y)==(x2*x2+y2*y2) && x==x2 && y<y2)
                return true;
            else
                return false;
        };

        priority_queue<Point,vector<Point>,decltype( compare)> maxheap( compare);
        for(auto & point:points)
            {
                maxheap.push(point);
                if(maxheap.size()>k)
                    maxheap.pop();
            }
        vector<Point> ret;
        while(maxheap.size())
            {
                Point p=maxheap.top();
                p.x+=origin.x;
                p.y+=origin.y;
                ret.push_back(p);
                maxheap.pop();
            }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};