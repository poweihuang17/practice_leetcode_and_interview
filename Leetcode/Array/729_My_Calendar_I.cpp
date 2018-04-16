class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it1=table.upper_bound(start);
        while(it1!=table.end())
        {
        	if(end<=it1->second) it1++;
        	else
        		return false;
        }
        table[end]=start;
        return true; 
    }

private:
	map<int,int> table;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */