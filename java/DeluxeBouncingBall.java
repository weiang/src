/*************************************************************************
 *  Compilation:  javac DeluxeBouncingBall.java
 *  Execution:    java DeluxeBouncingBall
 *  Dependencies: StdDraw.java StdAudio.java
 *                http://www.cs.princeton.edu/introcs/15inout/laser.wav
 *                http://www.cs.princeton.edu/introcs/15inout/pop.wav
 *                http://www.cs.princeton.edu/introcs/15inout/earth.gif
 *
 *  Implementation of a 2-d bouncing ball in the box from (-1, -1) to (1, 1).
 *
 *  % java DeluxeBouncingBall
 *
 *************************************************************************/

public class DeluxeBouncingBall { 
    public static void main(String[] args) {
        double rx = .480, ry = .860;     // position
        double vx = .015, vy = .023;     // velocity
        double radius = .03;             // a hack since "earth.gif" is in pixels

        // set the scale of the coordinate system
        StdDraw.setXscale(-1.0, 1.0);
        StdDraw.setYscale(-1.0, 1.0);


        // main animation loop
        while (true) { 
            if (Math.abs(rx + vx) + radius > 1.0) { vx = -vx; StdAudio.play("hip.mp3"); }
            if (Math.abs(ry + vy) + radius > 1.0) { vy = -vy; StdAudio.play("hip.mp3");   }
            rx = rx + vx; 
            ry = ry + vy; 
            StdDraw.filledSquare(0.0, 0.0, 1.0);
            StdDraw.picture(rx, ry, "earth.gif");
            StdDraw.show(20); 
        } 
    } 
} 
