class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(recent.count(message)!=0)
        {
            if(recent[message]+10>timestamp)
            {
        	    return false;
            }
            else
            {
                recent[message]=timestamp;
                return true;
            }

        }
        else 
        {
            recent[message]=timestamp;
        	return true;
        }
    }
private:
	unordered_map<string, int> recent;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */