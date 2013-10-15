/*************************************************************************
	> File Name: Triangle.java
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月01日 星期二 16时01分07秒
    > Describition: 
 ************************************************************************/

public class Triangle {
	public static void main(String[] args)
	{
		double t = Math.sqrt(3.0) / 2.0;
		StdDraw.line(0.0, 0.0, 1.0, 0.0);
		StdDraw.line(1.0, 0.0, 0.5, t);
		StdDraw.line(0.5, t, 0.0, 0.0);
		StdDraw.point(0.5, t / 3.0);
	}
}


