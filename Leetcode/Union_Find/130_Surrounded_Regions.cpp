#include <iostream>
#include <vector>
using namespace std;

//This implementation doesn't return a class...
//Need one more API...
//Need to check other UF implementation.
class UF // union find
{
	private: 
		int *id;  // parent link
		int *sz; // size of component for roots
		int count; // number of components

	public:
		UF(int N)
		{
			count=N;
			id=new int[N];
			sz=new int[N];
			for (int i=0;i<N;i++)
			{
				id[i]=i;
				sz[i]=i;
			}
		}
		~UF()
		{
			delete id;
			delete sz;
		}

		int getCount()
		{
			return count;
		}

		int find(int i)
		{
			while(i != id[i])
			{
				id[i] = id[id[i]];  // path compression by halving
				i=id[i];
			}
			return i;
		}

		bool is_connected(int p, int q)
		{
			return find(p)==find(q); // check if two union is connected
		}

		void connect(int p , int q) // Merge
		{
			int i=find(p);
			int j=find(q);
			if (i==j) return;
			//make smaller root point to larger one.
			if(sz[i]<sz[j])
			{
				id[i]=j;
				sz[j]+=sz[i];
			}
			else
			{
				id[j]=i;
				sz[i]+=sz[j];
			}
			count--;
		}
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {

    	int n = board.size();
    	if (n == 0) return;
    	int m = board[0].size();
    	UF uf = UF(n * m + 1); // n * m is a dummy node, which means boundary.

    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			if (  (i==0 || i==n-1 || j==0 || j==m-1) && board[i][j]=='O' )
    				uf.connect(i * m + j, n*m);

    			else if (board[i][j] == 'O')
    			{
    				if(board[i - 1][j] == 'O')
    					uf.connect(i*m+j, (i-1)*m+j);
    				if (board[i+1][j]=='O')
    					uf.connect(i*m+j,(i+1)*m+j);
    				if (board[i][j-1]=='O')
    					uf.connect(i*m+j, i*m+j-1);
    				if (board[i][j+1]=='O')
    					uf.connect(i*m+j, i*m+j+1);
    			}

    			cout<<uf.getCount()<<'\n';
    		}
    	}

    	for(int i=1;i<n-1;i++)
    		for(int j=1;j<m-1;j++)
    			{
    				if (!uf.is_connected(i*m+j,m*n))
    					board[i][j]='X';
    			}
        
    }
};


int main()
{
	vector<vector<char>> board =
    {
{'O','X','X','O','X'},{'X','O','O','X','O'},{'X','O','X','O','X'},{'O','X','O','O','O'},{'X','X','O','X','O'}
    };
    for (auto a : board)
    {
        for (auto b : a)
        {
            cout << b << ' ';
        }
        cout << endl;
    }
    cout << endl;
    auto sl = new Solution();
    sl->solve(board);
    for (auto a : board)
    {
        for (auto b : a)
        {
            cout << b << ' ';
        }
        cout << endl;
    }
    //system('pause');
    return 0;
}