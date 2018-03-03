public class BreadthFirstPaths
{
	private boolean [] marked;
	private int [] edgeTo;
	private final int s;
	private int [] distTo;

	public BreadthFirstPaths(Graph G, int S)
	{
		dfs(G,s);
	}

	private void bfs(Graph G, int s)
	{
		Queue<Integer> q=new Queue<Integer>();
		q.enqueue(s);
		marked[s]=true;
		disTo[s]=0;

		while(!q.isEmpty())
		{
			int v=q.dequeue();
			for(int w: G.adj(v))
			{
				if(!marked[w])
				{
					q.enqueue(w);
					marked[w]=true;
					edgeTo[w]=v;
					distTo[w]=distTo[v]+1;
				}
			}
		}
	}
}