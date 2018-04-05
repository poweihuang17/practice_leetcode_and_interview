class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        myqueue.push(x);
        for(int i=0;i<myqueue.size()-1;i++)
        {
            myqueue.push(myqueue.front());
            myqueue.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x=myqueue.front();
        myqueue.pop();
        return x; 
    }
    
    /** Get the top element. */
    int top() {
        return myqueue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return myqueue.empty();
    }

private:
    queue<int> myqueue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */