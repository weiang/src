/*************************************************************************
	> File Name: Shape.java
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月01日 星期二 16时26分42秒
    > Describition: 
 ************************************************************************/

public class Shape {
	public static void main(String[] args)
	{
		StdDraw.square(.2, .8, .1);
		StdDraw.filledSquare(.8, .8, .2);
		StdDraw.circle(.8, .2, .2);
		double[] xd = {.1, .2, .3, .2};
		double[] yd = {.2, .3, .2, .1};
		StdDraw.filledPolygon(xd, yd);
		StdDraw.text(.2, .5, "black text");
		StdDraw.setPenColor(StdDraw.WHITE);
		StdDraw.text(.8, .8, "white text");
	}
}

