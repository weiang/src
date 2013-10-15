/*************************************************************************
 *  Compilation:  javac RandomSurferHistogram.java
 *  Execution:    java RandomSurferHistogram T
 *  Data files:   http://introcs.cs.princeton.edu/16pagerank/tiny.txt
 *                http://introcs.cs.princeton.edu/16pagerank/medium.txt
 *
 *  % java Transition < tiny.txt | java RandomSurferHistogram 1000000
 *   0.27297 0.26583 0.14598 0.24729 0.06793
 *
 *************************************************************************/

public class RandomSurferHistogram {
    public static void main(String[] args) {


        int T = Integer.parseInt(args[0]);    // number of moves
        int N = StdIn.readInt();              // number of pages
        StdIn.readInt();                      // ignore integer required by input format

        // Read transition matrix.
        double[][] p = new double[N][N];     // p[i][j] = prob. that surfer moves from page i to page j
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) 
                p[i][j] = StdIn.readDouble(); 


        int[] freq = new int[N];            // freq[i] = # times surfer hits page i
 
        // Start at page 0. 
        int page = 0;

        for (int t = 0; t < T; t++) {

            // Make one random move. 
            double r = Math.random(); 
            double sum = 0.0; 
            for (int j = 0; j < N; j++) 
            {
                // Find interval containing r. 
                sum += p[page][j]; 
                if (r < sum) { page = j; break; } 
            } 
            freq[page]++; 

            // plot histogram of frequencies
            StdDraw.clear();
            StdDraw.setXscale(-1, N);
            StdDraw.setYscale(0, t);
            for (int k = 0; k < N; k++) {
                StdDraw.filledRectangle(k, freq[k]/2.0, 0.25, freq[k]/2.0);
            }
            StdDraw.show(20);

        } 




        // Print page ranks. 
        for (int i = 0; i < N; i++) {
            StdOut.printf("%8.5f", (double) freq[i] / T); 
        }
        StdOut.println(); 
    }  
} 
