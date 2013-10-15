/*************************************************************************
	> File Name: MaxMin.java
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月01日 星期二 21时58分25秒
    > Describition: 
 ************************************************************************/
public class MaxMin {
	public static void main(String[] args)
	{
		int max, min;
		while (true) {
			max = min = StdIn.readInt();
			if (max > 0)
				break;
			StdOut.printf("Please enter positive integers\n");
		}
		while (!StdIn.isEmpty()) {
			int in = StdIn.readInt();
			if (in < 0) {
				StdOut.printf("Please enter positive integers\n");
				continue;
			}
			if (in < min)
				min = in;
			else if (in > max)
				max = in;
		}
		StdOut.printf("Max = %d, Min = %d\n", max, min);
	}
}

