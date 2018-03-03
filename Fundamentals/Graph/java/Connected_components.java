// Not the same as union find?!
// I thought it should be the same as union find.
// Actually, after I saw the video, I thought it's the same as union find.

// I need to find out the difference between this and the union find.

public class CC
{
	private boolean marked[];
	private int [] id;
	private int count;

	public CC(Graph G)
	{
		marked=new boolean[G.V()];
		id =new int [G.V()];
		for (int v=0; v<G.V();v++)
		{
			if(!marked[v])
			{
				dfs(G,v);
				count++;
			}
		}
	}

	public int count()
	{
		return count;
	}
	public int id(int v){
		return id[v];
	}

	public bool is_connected(int v, int w)
	{
		return id[v]==id[w];
	}
	private void dfs(Graph G, int v)
	{
		marked[v]=true;
		id[v]=count;
		for(int w: G.adj(v))
			if(!marked[w])
				dfs(G,w);
	}
}