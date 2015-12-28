/*Student Name:
  Lab Assignment: EECS 168 Lab5 */
package edu.ku.eecs168.lab5;

import java.util.Random;


import android.graphics.Color;
import android.os.Bundle;


public class Lab5 extends AbsLab5 {

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

	
	@Override
	public void paint(Graphics canvas) {
		
		
		int myColor;
		
		
		int r  = 0;
		
		double theta = 2*Math.PI/(numShapes);
		int rad = 350, h=350, k=550;

		
		canvas.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
		
		//large circle Center
		canvas.setColor(Color.BLACK);
		canvas.drawOval(20, 150, 750, 750);
		canvas.drawRect(20, 150, 750, 750);
		canvas.fillOval(20, 150, 10, 10);
		//center
		canvas.fillOval(395, 525, 10, 10);
		
		
		
		
		for(int i=1; i<=numShapes; i++){
		//Variables
			
		myColor = rgbToColor(255,r,255,255);
		int x = (int) (h+rad*Math.cos(i*theta));
		int y = (int) (k+rad*Math.sin(i*theta));
		//random color for circles
		
		
		if (numShapes > 25 ){
		r = r+2
			
		} else
			r = r + 10
		
		//position
		canvas.setColor(myColor);
		canvas.fillOval(x, y, 100, 100);
		canvas.setColor(Color.BLACK);
		canvas.drawOval(x, y, 100, 100);
		
		canvas.drawRect(x, y, 100, 100);
	
		}
		
	}

}
