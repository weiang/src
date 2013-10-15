
/*************************************************************************
 *  Compilation:  javac Dragon.java
 *  Execution:    echo F F | java Dragon | java Dragon | java Dragon
 *  
 *  Prints the instructions for drawing a dragon curve of orders N.
 * 
 *  % echo F F | java Dragon 
 *  FLF FRF
 *
 *  % echo F F | java Dragon | java Dragon 
 *  FLFLFRF FLFRFRF
 *
 *  % echo F F | java Dragon | java Dragon | java Dragon
 *  FLFLFRFLFLFRFRF FLFLFRFRFLFRFRF
 *
 *************************************************************************/

public class Dragon { 
   public static void main(String[] args) { 
      String dragon = StdIn.readString();
      String nogard = StdIn.readString();
      System.out.print(dragon + "L" + nogard);
      System.out.print(" ");
      System.out.print(dragon + "R" + nogard);
      System.out.println();
   }

}
