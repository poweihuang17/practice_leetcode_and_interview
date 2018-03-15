#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    	if(board.empty()) return board;
    	queue<vector<int>> myqueue;
    	myqueue.push(click);
        vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
    	while(!myqueue.empty())
    	{

	    	click=myqueue.front();
	    	myqueue.pop();
	   		char clicked=board[click[0]][click[1]];
	        if(clicked=='M')
	        	{
	        		board[click[0]][click[1]]='X';
	        		return board;
	        	}
	        else if(clicked=='E')
	        {
	        	int number=count_mine(board,click);
	        	if(number==0)
	        	{
	        		board[click[0]][click[1]]='B';
                    
	        		for (auto & dir:dirs)
						{
							int new_r=click[0]+dir[0];
							int new_c=click[1]+dir[1];
							if( new_r>=0 && new_r<board.size() && new_c>=0 && new_c<board[0].size() &&  board[new_r][new_c]=='E')
								{	
									//cout<<new_r<<' '<<new_c<<endl;
									myqueue.push({new_r,new_c});
								}
						}

	        	}
	        	else 
	        	{
	        		board[click[0]][click[1]]='0'+number;

	        	}
	        }
	        else 
	        	continue;
	        /*
	        for(auto & row : board)
	        {
	        	for(auto & c: row)
	        	{
	        		cout<<c<<' ';
	        	}
	        	cout<<endl;
	        }
	        cout<<endl;
	        */
    	}
    	return board;

    }

private:
	int count_mine(vector<vector<char>> & board, vector<int> & click)
	{
		vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
		int count=0;
		for (auto & dir:dirs)
		{
			int new_r=click[0]+dir[0];
			int new_c=click[1]+dir[1];
			if( new_r>=0 && new_r<board.size() && new_c>=0 && new_c<board[0].size() &&  board[new_r][new_c]=='M')
				count++;
		}
		return count;
	}
};



int main()
{
	Solution s;
	vector<vector <char> > board{{'E','E','E','E','E'},{'E','E','M','E','E'},{'E','E','E','E','E'},{'E','E','E','E','E'}} ;
	vector<int> click{3,0};
	s.updateBoard(board, click);
}