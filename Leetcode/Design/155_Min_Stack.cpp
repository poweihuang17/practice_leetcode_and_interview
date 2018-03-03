#include <utility>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.size())
            s.push(make_pair(x,min(x, this->getMin())));
        else
            s.push(make_pair(x,x));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;   
    }

private:
    //Save current value and current min value.
    stack < pair<int,int> > s;

};

int main()
{
    MinStack m;
    m.push(-2);
    m.push(0);
    m.push(-3);
    m.getMin();
    m.pop();
    m.top();
    m.getMin();
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */