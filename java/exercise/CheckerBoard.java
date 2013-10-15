/*************************************************************************
	> File Name: CheckerBoard.java
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月02日 星期三 00时22分47秒
    > Describition: 
 ************************************************************************/

public class CheckerBoard {
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		int color = 0;
		final double length = 1.0 / N;
		double vx = length / 2;
		double vy = length / 2;
	
		for (int i = 0; i != N; i ++) {
			if (i % 2 == 0) {
				StdDraw.setPenColor(StdDraw.RED);
				color = 0;
			}
			else { 
				StdDraw.setPenColor(StdDraw.BLACK);
				color = 1;
			}
			for (int j = 0; j != N; j ++) {
				if (color == 0) {
					StdDraw.setPenColor(StdDraw.RED);
					color = 1;
				}
				else {
					StdDraw.setPenColor(StdDraw.BLACK);
					color = 0;
				}
				StdDraw.filledSquare(vx, vy, length / 2.0);
				vx += length;
			}
				vy += length;
				vx = length / 2;
		}
	}
}
