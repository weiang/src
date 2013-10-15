/*************************************************************************
	> File Name: Percolation.java
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月02日 星期三 21时02分36秒
    > Describition: 
 ************************************************************************/

public class Percolation {
	private int grid[];	// Use N * N size array to represent the grid's state
	private final int BLOCK = -1;
	private final int OPEN = 1;
	private final int FULL = 2;
	private int size;	// The grid's length

	/* Convert 2-dem (x, y) into 1-dem coordiate */
	private int index(int i, int j) 
	{
		return (i - 1) * size + j - 1;
	}

	private boolean isVaild(int i)
	{
		return  i >= 0 && i < size * size;
	}

	public  Percolation(int N)
	{
		size = N;
		grid = new int[N * N];

		/* Initialize grid to BLOCK state*/
		for (int i = 0; i != N * N; i ++)
			grid[i] = BLOCK;
	}

	public void open(int i, int j)
	{
		int idx = index(i, j);
		
		if (!isvaild(idx)) 
			return;		// Index into array is not vaild

		if (i == 1)		// First row, colored with FULL
			grid[idx] = FULL;
		grid[index(i, j)] = OPEN;
	}

	public boolean isOpen(int i, int j)
	{
		return grid[index(i, j)] == OPEN;
	}

	public boolean isFull(int i, int j)
	{
		return grid[index(i, j)] == FULL;
	}

	public boolean percolates()
	{
		for (int i = 0; i < size; i ++)
			if (isfull(size, i + 1))
				return true;
		return false;
	}
}


