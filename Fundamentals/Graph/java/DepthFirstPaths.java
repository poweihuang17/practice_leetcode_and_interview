// Array in Java doesn't need a size when initialization?
// Magic : Why everything is iterable? A stack and a bag are all iterable<Integer>?
// Is that the so-called interface?

public class DepthFirstPaths
{
	private boolean [] marked;
	private int [] edgeTo;
	private int s;
	

	public DepthFirstPaths(Graph G, int S)
	{
		dfs(G,s);
	}

	private void dfs(Graph, int v)
	{
		marked[v]=true;
		for(int w: G.adj(v))
			if(!marked[w])
			{
				dfs(G,w);
				edgeTo[w]=v;
			}
	}

	public boolean hasPathTo(int v)
	{
		return marked[v];
	}

	public Iterable<Integer> pathTo(int v)
	{
		if(!hasPathto(v)) return null;
		Stack<Integer> path=new Stack<Integer>();
		for(int x=v; x!=s; x=edgeTo[x])
			path.push(x);
		path.push(s);
		return path;
	}
}