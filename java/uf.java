/*************************************************************************
	> File Name: uf.java
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年09月29日 星期日 11时41分04秒
    > Describition: 
 ************************************************************************/

public class UF
{
	private int[] id;
	private int count;

	public UF(int n)
	{
		// Initialize component id array.
		count = n;
		id = new int[n];
		for (int i = 0; i < n; i ++)
			id[i] = i;
	}

	public int count()
	{
		return count;
	}

	public boolean connected(int p, int q)
	{
		return find(p) == find(q);
	}

	public int find(int p)
	{
		return id[p];
	}

	public void union(int p, int q)
	{
		int pid = id[p];
		int qid = id[q];

		if (pid == qid) return;
		count --;
		for (int i = 0; i != id.length; i ++) 
			if (id[i] == qid) id[i] = pid;
	}

	public static void main(String[] args)
	{
		int n = StdIn.readInt();
		UF uf = new UF(n);
		while (!StdIn.isEmpty()) {
			int p = StdIn.readInt();
			int q = StdIn.readInt();
			if (uf.connected(p, q)) continue;
			uf.union(p, q);
			StdOut.println(p + " " + q);
		}
		StdOut.println(uf.count() + " components");
	}
}
