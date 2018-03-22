class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        instack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp=peek();
        outstack.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if(outstack.empty())
            while(instack.size()>0)
            {
                outstack.push(instack.top());
                instack.pop();
            }

        return outstack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (instack.empty() && outstack.empty());
        
    }
private:
    stack<int> instack,outstack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */