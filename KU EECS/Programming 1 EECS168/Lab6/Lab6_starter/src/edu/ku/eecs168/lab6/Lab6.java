/*Lab6: EECS 168/169 Part2
  Partially Modified by: Nishitha Ayyalapu */
package edu.ku.eecs168.lab6;

import java.util.Random;

import android.graphics.Color;
import android.os.Bundle;


public class Lab6 extends AbsLab6 {

	private int numShapes = 0;
	private Random random;
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		random = new Random();
	}
	
	@Override
	public void onDialogReturned(int num) {
		numShapes = num;
		repaint();
	}
	
	// The setColor method of the Graphics class expects color to be specified as a single int.
	// This routine converts RGBalpha values into a single int that setColor can understand.
	// Specify the red, green, blue and alpha values as integers between 0 and 255.
	// Alpha is a transparency component - an alpha of 255 is fully opaque, 
	//   while an alpha of 0 is transparent.
	// The output of rgbToColor is an integer that is in the format expected by setColor,
	// which is specified by a hexidecimal value of the format 0xAARRGGBB
	public int rgbToColor(int red, int green, int blue, int alpha) {
		int color = 0;
		color += blue;
		color += 256*green;
		color += 256*256*red;
		color += 256*256*256*alpha;
		return color;
	}
	
	//declaring center of the circular contour (h,k)
	public static final int radius = 300;		//radius of the outer circular contour
	public static final int offset_x = 20;		//x_coordinate of contour's imaginary rectangle
	public static final int offset_y = 20;		//y_coordinate of contour's imaginary rectangle
	public static final int h = offset_x+radius;//x_coordinate of center of outer circular contour 
	public static final int k = offset_y+radius;//y_coordinate of center of outer circular contour 
	
	//x_of_theta method returns x-coordinate of the point, 
	//located at an "angle" on the circle of "radius" = 300
	public int x_of_theta(double angle) {
		int x = (int)(h+(radius*Math.cos(angle)));
		return x;
		
		
	}
	
	//y_of_theta method returns y-coordinate of the point, 
	//located at an "angle" on the circle of "radius" = 300
	public int y_of_theta(double angle) {
		int y = (int)(k+ (radius*Math.sin(angle)));
		return y;
		
		
	}
	

	@Override
	public void paint(Graphics canvas) {
		
		canvas.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());//clear the screen
		canvas.setColor(rgbToColor(0,81,186,255));//set color as KU blue, you can change it to whatever color you want
		//TODO create a nested for for-loop which will draw Lines between points on the circle
		//declaring variables
		 double theta = 2*Math.PI/(numShapes);
		 
		 //first for loop
		 for (int i=1; i<=numShapes; i++ ){
			 //setting first angle
			 double firstPosition = theta*i;
			 
			 int x1 = x_of_theta(firstPosition);
			 int y1 = y_of_theta(firstPosition);
			 
			 //nester for loop
			 for (int k= i+2; k<= numShapes; k+=2 ){
			 
				 //inner points
				 double circlePoints = theta*k;
				 
				//position of x2 and y2
				 int x2 = x_of_theta(circlePoints);
				 int y2 = y_of_theta(circlePoints);
				
			canvas.drawLine(x1,y1,x2,y2);	 
			 }
		 }
		
	}

}
