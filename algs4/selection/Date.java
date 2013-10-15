/*************************************************************************
	> File Name: Date.java
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月12日 星期六 20时51分03秒
    > Describition: 
 ************************************************************************/
public class Date implements Comparable<Date>
{
	private final int month, day, year;

	public Date(int m, int d, int y)
	{
		month = m;
		day = d;
		year = y;
	}
	
	public int compareTo(Date that)
	{
		if (this.year < that.year) return -1;
		if (this.year > that.year) return 1;
		if (this.month < that.month) return -1;
		if (this.month > that.month) return 1;
		if (this.day < that.day) return -1;
		if (this.day > that.day) return 1;
		return 0;
	}
}

