class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minheap.empty() || num>=minheap.top())
            minheap.push(num);
        else
            maxheap.push(num);
    	
        if(minheap.size()>maxheap.size()+1)
    	{
    			maxheap.push(minheap.top());
    			minheap.pop();
    	}
        else if(maxheap.size()>minheap.size()+1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size())
            return ((double)minheap.top()+(double)(maxheap.top()))/2.0;
        else if(minheap.size()>maxheap.size())
            return (double)minheap.top();
        else
            return (double)maxheap.top();
    }

private:
	priority_queue<int,vector<int>,greater<int>> minheap;
	priority_queue<int,vector<int>,less<int>> maxheap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */