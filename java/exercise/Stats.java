/*************************************************************************
	> File Name: Stats.java
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月01日 星期二 22时17分25秒
    > Describition: 
 ************************************************************************/

public class Stats {
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		double sum = 0.0;
		double[] in = new double[N];
		for (int i = 0; i != N; i ++) {
			in[i] = StdIn.readDouble();
			sum += in[i];
		}
		double average = sum / N;
		double sd = 0.0;
		for (int i = 0;	i != N; i ++) {
			sd += Math.pow(average - in[i], 2);
		}
		sd /= N - 1;
		StdOut.println("Average = " + average + ", Sd = " + sd);
	}
}
