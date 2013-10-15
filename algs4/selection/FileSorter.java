/*************************************************************************
	> File Name: FileSorter.java
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月12日 星期六 20时38分43秒
    > Describition: 
 ************************************************************************/
import java.io.File;

public class FileSorter
{
	public static void main(String[] args)
	{
		File directory = new File(args[0]);
		File[] files = directory.listFiles();
		Selection.sort(files);
		for (int i = 0; i < files.length; i ++)
			StdOut.println(files[i].getName());
	}
}
