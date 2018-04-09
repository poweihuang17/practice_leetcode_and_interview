class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x=0;
        int o=0;

        for(int i=0;i<3;i++)
        {
        	for(auto & c: board[i])
        	{
        		if(c=='X') x++;
        		else if(c=='O') o++;
        	}
        }

        if(x<o || x>o+1) return false;

       	int counter=0;
       	
       	for(int i=0;i<3;i++)
       		{
       			counter+=getState(board[i][0],board[i][1],board[i][2]);
       			counter+=getState(board[0][i],board[1][i],board[2][i]);
       		}
       	counter+=getState(board[0][0],board[1][1],board[2][2]);
       	counter+=getState(board[0][2],board[1][1],board[2][0]);

       	return counter==0 || ( (counter==1 || counter==2) && x>o)  || (counter==-10) && x==o;
    }
private:

	int getState(char c1, char c2, char c3)
	{
		if(c1!=' ' && c1==c2 && c2==c3) return c1=='X'? 1: -10;
		else return 0;
	}
};