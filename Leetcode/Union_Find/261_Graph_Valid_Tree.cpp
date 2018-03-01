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
    bool validTree(int n, vector<pair<int, int>>& edges) {
    	UF u=UF(n);
    	for (auto edge : edges)
    	{
    		if (u.find(edge.first)==u.find(edge.second))
    			return false;

    		u.connect(edge.first,edge.second);
    	}
        return u.getCount()==1;
    }
};