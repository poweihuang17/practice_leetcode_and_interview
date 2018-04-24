class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        frequency[start]+=1;
        frequency[end]-=1;
        int cnt=0;
        int ret=INT_MIN;
        for(auto & kv:frequency)
        {
            cnt+=kv.second;
            ret=max(cnt,ret);
        }
        return ret;
    }
private:
    map<int,int> frequency;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */