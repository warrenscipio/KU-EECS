package edu.ku.eecs168.lab5;

import java.util.Random;
import java.lang.Math;

import android.graphics.Color;
import android.os.Bundle;


public class Extracredit extends AbsLab5 {

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
		
		

		canvas.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
		
		int r  = random.nextInt(256);
		int g  = random.nextInt(256);
		int b  = random.nextInt(256);
		int myColor = rgbToColor(r,g,b,255);
		double theta = 2*Math.PI/(numShapes);
		int rad = 5, h, k;
		
		
		canvas.setColor(Color.BLACK);
		canvas.drawOval((canvas.getWidth())/2, (canvas.getHeight())/2, 200, 200);
		
		
		
		for(int i=1; i<=numShapes; i++){
		
		
		
		
		canvas.setColor(Color.RED);
		canvas.fillOval(4, 9, 200, 200);
		canvas.setColor(Color.BLACK);
		canvas.drawOval(4, 9, 200, 200);
		
		
	
		}
		
	}

}
