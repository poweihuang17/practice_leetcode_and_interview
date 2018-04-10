class Solution {
public:
    string numberToWords(int num) {


        if(num==0) return "Zero";

        int i=0;
        string words="";
        while(num>0)
        {
        	if(num%1000!=0)
        		words=helper(num%1000)+thousands[i]+" "+words;
        	num/=1000;
        	i++;
        }
        ltrim(words);
        rtrim(words);
        return words;
    }
private:
    // trim from start (in place)
    static inline void ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
        }));
    }

    // trim from end (in place)
    static inline void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

	string helper(int num)
	{
		if(num==0)
			return "";
		else if(num<20)
			return less_than_twenty[num]+" ";
		else if(num<100)
			return tens[num/10]+" "+helper(num%10);
		else
			return less_than_twenty[num/100]+" Hundred "+helper(num%100);
	}
	
	vector<string> less_than_twenty={"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens={"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands={"", "Thousand", "Million", "Billion"};
};