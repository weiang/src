/*************************************************************************
	> File Name: Selection.java
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月12日 星期六 19时39分41秒
    > Describition: 
 ************************************************************************/

public class Selection
{
	public static void sort(Comparable[] a)
	{
		int n = a.length;
		for (int i = 0; i < n - 1; i ++) {
			int min = i;
			for (int j = i + 1; j < n; j ++)
				if (less(a[j], a[min]))
						min = j;
			exch(a, i, min);
		}
	}

	private static boolean less(Comparable a, Comparable b)
	{
		return a.compareTo(b) < 0;
	}

	private static void exch(Comparable[] a, int i, int j)
	{
		Comparable tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}

	private static void show(Comparable[] a)
	{
		for (int i = 0; i < a.length; i ++)
			StdOut.print(a[i] + " ");
		StdOut.println();
	}

	public static boolean isSorted(Comparable[] a)
	{
		for (int i = 0; i < a.length - 1; i ++)
			if (less(a[i + 1], a[i]))
				return false;
		return true;
	}

	public static void main(String[] args)
	{
		String[] a = In.readStrings();
		sort(a);
		assert isSorted(a);
		show(a);
	}
}

