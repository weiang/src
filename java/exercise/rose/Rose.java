
public class Rose
{
  public static void main(String[] args)
  {
      int n = Integer.parseInt(args[0]);
      double p = Double.parseDouble(args[1]);
      
      double r = Math.toRadians(360.0) / n;
      double[] x = new double[n];
      double[] y = new double[n];
      StdDraw.setXscale(-1.0, 1.0);
      StdDraw.setYscale(-1.0, 1.0);
      
//	  StdDraw.point(0.5, 0.5);
//	  StdDraw.setPenColor(StdDraw.RED);
	  int j = 0;
      for (double i = 0.0; i != Math.toRadians(360.0) && j < n; i += r,j ++) { 
//		  System.out.println(i);
          x[j] = Math.cos(i);
          y[j] = Math.sin(i);
//		  System.out.println("x, y: " + x[j] + " " + y[j]);
          StdDraw.filledCircle(x[j], y[j], 0.01);
        }
	  for (int i = 0; i != n; i ++) {
		  for (int k = 0; k < Math.round(n * p); k ++) {
			  int tmp = (int)Math.round(Math.random() * n);
			  if (tmp >= n) 
				  tmp --;
			  System.out.println(tmp);
			  StdDraw.line(x[i], y[i], x[tmp], y[tmp]);
		  }
	  }
    }
}
