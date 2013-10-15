/*************************************************************************
	> File Name: Fib.java
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月07日 星期一 22时31分48秒
    > Describition: 
 ************************************************************************/

public class Fib {
	public static void main(String[] args)
	{
		double x1, y1, x2, y2;
		int n = Integer.parseInt(args[0]);
		
		StdDraw.setXscale(-2, 60);
		StdDraw.setYscale(0, 30);
	
//		StdDraw.filledCircle(10, 5000, 0.1);
		StdDraw.line(0.0, 0.0, 0.0, 29.0);	// Y
		StdDraw.line(0.0, 29.0, -1.0, 28.5);
		StdDraw.line(0.0, 29.0, 1.0, 28.5);
		StdDraw.line(0.0, 0.0, 55, 0.0);	// X
		StdDraw.line(55, 0, 54, 0.5);
		StdDraw.line(55, 0, 54, -0.5);
		StdDraw.text(0.0, 30.0, "T/s");
		StdDraw.text(57.0, 0.0, "N");
		x1 = y1 = 0.0;
		StdDraw.filledCircle(0.0, 0.0, 0.1);
//		StdDraw.text(0.0, -1000, "0");
		for (int i = 0; i <= 55;i += 5) 
			StdDraw.text(i, -1, new Integer(i).toString());
		for (int i = 0; i < 30; i += 3)
			StdDraw.text(-2, i, new Integer(i).toString());
		while (n > 0) {
			x2 = StdIn.readDouble();
			y2 = StdIn.readDouble() / 1000;
			StdDraw.filledCircle(x2, y2, 0.1);
			StdDraw.line(x1, y1, x2, y2);
//			if (n >= 35)
//				StdDraw.text(x2 + .5, y2 + .5, "(" + new Double(x2).toString() + ", " + new Double(y2).toString() + ")");
			x1 = x2;
			y1 = y2;
			n --;
		}

	}
}
