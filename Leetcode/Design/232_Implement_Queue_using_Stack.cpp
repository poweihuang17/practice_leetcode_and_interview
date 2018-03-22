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
        while(instack.size()>0){
            outstack.push(instack.top());
            instack.pop();
        }
        int temp=outstack.top();
        outstack.pop();
        while(outstack.size()>0)
        {
            instack.push(outstack.top());
            outstack.pop();
        }
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        while(instack.size()>0){
            outstack.push(instack.top());
            instack.pop();
        }
        int temp=outstack.top();
        while(outstack.size()>0)
        {
            instack.push(outstack.top());
            outstack.pop();
        }
        return temp;
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