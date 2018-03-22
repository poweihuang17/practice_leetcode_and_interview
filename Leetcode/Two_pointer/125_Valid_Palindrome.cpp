class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(!isalnum(s[j])) j--;
        while(!isalnum(s[i])) i++;

        while(i<j)
        {

        	if(tolower(s[i])!=tolower(s[j]) )  return false; 
        	do{i++;} while(!isalnum(s[i]) );
        	do{j--;} while(!isalnum(s[j]));
        }
    	return true;
    }
};